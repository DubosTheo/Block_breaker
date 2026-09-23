#include "Racket.hpp"

#include <SFML/Graphics/RectangleShape.hpp>
#include <SFML/Window/Keyboard.hpp>

void racket::update(float deltaTime, sf::RenderWindow &window)
{
    _velocity = {0.0f, 0.0f};

    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::Left) || sf::Keyboard::isKeyPressed(sf::Keyboard::Key::Q))
        _velocity.x -= 1.0f;
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::Right) || sf::Keyboard::isKeyPressed(sf::Keyboard::Key::D))
        _velocity.x += 1.0f;
    _position += _velocity * _speed * deltaTime;
    float halfWidth = _shape->getGlobalBounds().size.x / 2.0f;
    if (_position.x - halfWidth < 0.0f)
        _position.x = halfWidth;
    if (_position.x + halfWidth > window.getSize().x)
        _position.x = window.getSize().x - halfWidth;
    setPosition(_position);
}

racket::racket(const sf::Vector2u &windowSize)
{
    init(windowSize);
}

void racket::init(const sf::Vector2u &windowSize)
{
    sf::Vector2f winSize = static_cast<sf::Vector2f>(windowSize);

    _size = { winSize.x * 0.16f, winSize.y * 0.025f };
    _velocity = {0.0f, 0.0f};
    _speed = 700.0f * (winSize.x / 1920.0f);

    auto rect = std::make_unique<sf::RectangleShape>(_size);
    rect->setOrigin({_size.x / 2.0f, _size.y / 2.0f});
    rect->setFillColor(sf::Color::Black);
    rect->setOutlineColor(sf::Color::Green);
    rect->setOutlineThickness(3.0f);
    _shape = std::move(rect);
    _position = { winSize.x * 0.50f, winSize.y * 0.95f };
    if (_shape) {
        _shape->setPosition(_position);
    }
}
