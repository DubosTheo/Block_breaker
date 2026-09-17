#pragma once
#include "Aobject.hpp"

class Brick : public Aobject {
private:
    sf::Vector2f _size;
public:
    Brick(sf::Vector2f position, const sf::Vector2u &windowSize);
    ~Brick() override = default;
    void update(float deltaTime, sf::RenderWindow &window) override;
    void init(sf::Vector2f position, const sf::Vector2u &windowSize);
};
