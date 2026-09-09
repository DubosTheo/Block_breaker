#pragma once

#include <SFML/Graphics.hpp>

class Iscene {
public:
    virtual ~Iscene() = default;
    virtual void handleEvent(sf::RenderWindow &window) = 0;
    virtual void update(float time) = 0;
    virtual void draw(sf::RenderWindow &window) = 0;
};
