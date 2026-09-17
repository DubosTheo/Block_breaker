#include "Brick.hpp"

#include <SFML/Graphics/RectangleShape.hpp>

Brick::Brick(sf::Vector2f position, const sf::Vector2u &windowSize)
{
    init(position, windowSize);
}

void Brick::init(sf::Vector2f position, const sf::Vector2u &windowSize)
{
    _position = position;
    _size = {150.f, 25.0f};
    auto rect = std::make_unique<sf::RectangleShape>(_size);
    rect->setOrigin({_size.x / 2.0f, _size.y / 2.0f});
    rect->setFillColor(sf::Color::Black);
    rect->setOutlineColor(sf::Color::Red);
    rect->setOutlineThickness(5);
    _shape = std::move(rect);
    setPosition(_position);
}

void Brick::update(float deltaTime, sf::RenderWindow &window)
{
}

