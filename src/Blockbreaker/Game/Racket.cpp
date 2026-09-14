#include "Racket.hpp"

#include <SFML/Graphics/RectangleShape.hpp>
#include <SFML/Window/Keyboard.hpp>

void racket::update(float deltaTime, sf::RenderWindow &window)
{
    _velocity.x = 0.0f;
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Left) || sf::Keyboard::isKeyPressed(sf::Keyboard::Q))
        _velocity.x -= 1.0f;
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Right) || sf::Keyboard::isKeyPressed(sf::Keyboard::D))
        _velocity.x += 1.0f;
    _position += _velocity * _speed * deltaTime;
    float halfWidth = _shape->getGlobalBounds().width / 2.0f;
    if (_position.x - halfWidth < 0.0f) _position.x = halfWidth;
    if (_position.x + halfWidth > window.getSize().x) _position.x = window.getSize().x - halfWidth;
    setPosition(_position);
}

racket::racket(const sf::Vector2u &windowSize)
{
    init(windowSize);
}

void racket::init(const sf::Vector2u &windowSize)
{
    _size = {100.0f, 100.0f};
    _position = {100, 100};
    _velocity = {0.0f, 0.0f};
    _speed = 400;
    auto rect = std::make_unique<sf::RectangleShape>(_size);
    rect->setOrigin(_size.x / 2.0f, _size.y / 2.0f);
    rect->setFillColor(sf::Color::Black);
    rect->setOutlineColor(sf::Color::Green);
    rect->setOutlineThickness(10);
    _shape = std::move(rect);
    _position = sf::Vector2f(windowSize.x / 2.0f, windowSize.y - 30.0f);
}
