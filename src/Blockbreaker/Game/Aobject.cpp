#include "Aobject.hpp"

void Aobject::draw(sf::RenderTarget &target, sf::RenderStates states) const
{
    if (_shape)
        target.draw(*_shape, states);
}

void Aobject::setPosition(sf::Vector2f position)
{
    _position = position;
    if (_shape)
        _shape->setPosition(_position);
}

