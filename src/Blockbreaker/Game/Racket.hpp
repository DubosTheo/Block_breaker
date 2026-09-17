#pragma once
#include "Aobject.hpp"

class racket : public Aobject {
private:
    sf::Vector2f _size;
public:
    racket(const sf::Vector2u &windowSize);
    ~racket() override = default;
    void update(float deltaTime, sf::RenderWindow &window) override;
    sf::Vector2f getSize() const {return _size;}
    void init(const sf::Vector2u &windowSize);
};
