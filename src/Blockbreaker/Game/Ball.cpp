#include "Ball.hpp"

#include <SFML/Graphics/CircleShape.hpp>

ball::ball(sf::Vector2u windowSize)
{
    sf::Vector2f winSize = static_cast<sf::Vector2f>(windowSize);

    _radius = winSize.x * 0.006f;
    _position = {winSize.x / 2.0f, winSize.y / 2.0f};
    auto circle = std::make_unique<sf::CircleShape>(_radius);

    circle->setOrigin({_radius, _radius});
    circle->setFillColor(sf::Color::Black);
    circle->setOutlineColor(sf::Color::Green);
    circle->setOutlineThickness(2.0f);
    _speed = 250.0f * (winSize.x / 950.0f);
    _velocity = {1.0f, -1.0f};
    _shape = std::move(circle);
    if (_shape) {
        _shape->setPosition(_position);
    }
}

void ball::update(float deltaTime, sf::RenderWindow &window)
{
    _position += _velocity * _speed * deltaTime;
    setPosition(_position);
}
