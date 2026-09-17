#pragma once
#include "Aobject.hpp"

class ball : public Aobject {
private:
    float _radius;
public:
    ball();
    ~ball() override = default;
    void update(float deltaTime, sf::RenderWindow &window) override;
    float getRadius() const {return _radius;}
};
