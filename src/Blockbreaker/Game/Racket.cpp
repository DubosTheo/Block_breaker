#include "Racket.hpp"
#include <SFML/Window/Keyboard.hpp>

racket::racket(const sf::Vector2u& windowSize) : _velocity(0.0f, 0.0f), _speed(400)
{
    sf::Vector2f size(150.0f, 20.0f);

    _rectShape.setSize(size);
    _rectShape.setOrigin(size.x / 2.0f, size.y / 2.0f);
    _rectShape.setFillColor(sf::Color::Black);
    _rectShape.setOutlineColor(sf::Color::Green);
    _rectShape.setOutlineThickness(4);
    _position.x = windowSize.x / 2.0f;
    _position.y = windowSize.y - 50.0f;
    _rectShape.setPosition(_position);
}

void racket::draw(sf::RenderWindow &window) const
{
    window.draw(_rectShape);
}

void racket::setPosition(const sf::Vector2f position)
{
    _position = position;
    _rectShape.setPosition(_position);
}

void racket::setSpeed(const float speed)
{
    _speed = speed;
}

void racket::setVelocity(const sf::Vector2f velocity)
{
    _velocity = velocity;
}

void racket::update(float dt, sf::RenderWindow &window)
{
    _velocity.x = 0.0f;

    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Left) || sf::Keyboard::isKeyPressed(sf::Keyboard::Q))
        _velocity.x = -1.0f;
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Right) || sf::Keyboard::isKeyPressed(sf::Keyboard::D))
        _velocity.x = 1.0f;
    _position += _velocity * _speed * dt;
    float halfWidth = _rectShape.getSize().x / 2.0f;
    sf::Vector2u windowSize = window.getSize();

    if (_position.x - halfWidth < 0.0f) {
        _position.x = halfWidth;
    }
    else if (_position.x + halfWidth > windowSize.x) {
        _position.x = windowSize.x - halfWidth;
    }
    _rectShape.setPosition(_position);
}
