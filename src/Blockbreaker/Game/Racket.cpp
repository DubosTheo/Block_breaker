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
    _size = {150.0f, 25.0f};
    _velocity = {0.0f, 0.0f};
    _speed = 600;
    auto rect = std::make_unique<sf::RectangleShape>(_size);
    rect->setOrigin({_size.x / 2.0f, _size.y / 2.0f});
    rect->setFillColor(sf::Color::Black);
    rect->setOutlineColor(sf::Color::Green);
    rect->setOutlineThickness(5);
    _shape = std::move(rect);
    _position = sf::Vector2f(windowSize.x / 2.0f, windowSize.y - 50.0f);
    setPosition(_position);
}
