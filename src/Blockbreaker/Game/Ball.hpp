#pragma once
#include "Aobject.hpp"

class ball final : public Aobject {
private:
    float _radius;
public:
    ball();
    ~ball() override = default;
    void update(float deltaTime, sf::RenderWindow &window) override;
    float getRadius() const {return _radius;}
};
