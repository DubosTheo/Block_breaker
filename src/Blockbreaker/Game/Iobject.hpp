#pragma once
#include <SFML/Graphics/Drawable.hpp>
#include <SFML/Graphics/RenderWindow.hpp>

class Iobject : public sf::Drawable{
public:
    Iobject() = default;
    virtual ~Iobject() override = default;
    virtual void update(float deltaTime, sf::RenderWindow &window) = 0;
};
