#include "Ball.hpp"

#include <SFML/Graphics/CircleShape.hpp>

ball::ball()
{
    _radius = 10;
    _position = {400, 400};
    auto circle = std::make_unique<sf::CircleShape>(_radius);
    circle->setOrigin({_radius, _radius});
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
    setPosition(_position);
}
