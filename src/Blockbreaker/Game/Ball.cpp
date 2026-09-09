#include "Ball.hpp"

ball::ball() : _circle_shape(10), _position(500, 400), _velocity(1,1), _speed(150)
{
    float radius = _circle_shape.getRadius();
    _circle_shape.setFillColor(sf::Color::White);
    _circle_shape.setOutlineColor(sf::Color::White);
    _circle_shape.setOrigin(radius, radius);
}

void ball::update(float dt, sf::RenderWindow &window)
{
    _position += _velocity * _speed * dt;

    float radius = _circle_shape.getRadius();
    sf::Vector2u windowSize = window.getSize();

    if (_position.x - radius <= 0.0f) {
        _velocity.x = std::abs(_velocity.x);
        _position.x = radius;
    } else if (_position.x + radius >= windowSize.x) {
        _velocity.x = -std::abs(_velocity.x);
        _position.x = windowSize.x - radius;
    }
    if (_position.y - radius <= 0.0f) {
        _velocity.y = std::abs(_velocity.y);
        _position.y = radius;
    } else if (_position.y + radius >= windowSize.y) {
        _velocity.y = -std::abs(_velocity.y);
        _position.y = windowSize.y - radius;
    }

    // 4. Synchronisation graphique
    _circle_shape.setPosition(_position);
}


void ball::draw(sf::RenderWindow &window) const
{
    window.draw(_circle_shape);
}


void ball::setPosition(const sf::Vector2f position)
{
    _position = position;
}

void ball::setSpeed(const float speed)
{
    _speed = speed;
}

void ball::setVelocity(const sf::Vector2f velocity)
{
    _velocity = velocity;
}

