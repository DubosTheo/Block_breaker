#include "Brick.hpp"

#include <SFML/Graphics/RectangleShape.hpp>

Brick::Brick(sf::Vector2f position, const sf::Vector2u &windowSize)
{
    init(position, windowSize);
}

void Brick::init(sf::Vector2f position, const sf::Vector2u &windowSize)
{
    sf::Vector2f winSize = static_cast<sf::Vector2f>(windowSize);

    _size = { winSize.x * 0.09f, winSize.y * 0.025f };

    _position = position;

    auto rect = std::make_unique<sf::RectangleShape>(_size);
    rect->setOrigin({_size.x / 2.0f, _size.y / 2.0f});
    rect->setFillColor(sf::Color::Black);
    rect->setOutlineColor(sf::Color::Red);
    rect->setOutlineThickness(3.0f);

    _shape = std::move(rect);

    if (_shape) {
        _shape->setPosition(_position);
    }
}

void Brick::update(float deltaTime, sf::RenderWindow &window)
{
}
