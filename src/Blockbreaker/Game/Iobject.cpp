#include "Iobject.hpp"

void Iobject::draw(sf::RenderTarget &target, sf::RenderStates states) const
{
    if (_shape)
        target.draw(*_shape, states);
}
