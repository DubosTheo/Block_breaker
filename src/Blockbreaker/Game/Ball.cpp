#include "Ball.hpp"

#include <SFML/Graphics/CircleShape.hpp>

ball::ball()
{
    _radius = 10;
    _position = {400, 300};
    auto circle = std::make_unique<sf::CircleShape>(_radius);
    circle->setOrigin(_radius, _radius);
    circle->setFillColor(sf::Color::Black);
    circle->setOutlineColor(sf::Color::Green);
    circle->setOutlineThickness(2);
    _speed = 300;
    _velocity = {0.707f, -0.707f};
    _shape = std::move(circle);
    setPosition(_position);
}

void ball::update(float deltaTime, sf::RenderWindow &window)
{
    _position += _velocity * _speed * deltaTime;
    if (_position.x - _radius < 0.0f || _position.x + _radius > window.getSize().x) {
        _velocity.x = -_velocity.x;
    }
    if (_position.y - _radius < 0.0f) {
        _velocity.y = -_velocity.y;
    }
    if (_position.y + _radius > window.getSize().y)
        window.close();
    setPosition(_position);
}
