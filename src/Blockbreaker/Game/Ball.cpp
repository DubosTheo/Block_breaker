#include "Ball.hpp"

#include <SFML/Graphics/CircleShape.hpp>

ball::ball()
{
    _radius = 10;
    _position = {200, 300};
    auto circle = std::make_unique<sf::CircleShape>(_radius);
    circle->setFillColor(sf::Color::Black);
    circle->setOutlineColor(sf::Color::Green);
    circle->setOutlineThickness(10);
    _speed = 400;
    _velocity = {0.707f, -0.707f};
    setPosition(_position);
}

void ball::update(float deltaTime, sf::RenderWindow &window)
{
    _position += _velocity * deltaTime;
    setPosition(_position);
}
