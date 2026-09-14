#pragma once
#include <memory>
#include <SFML/Graphics/RenderWindow.hpp>
#include <SFML/Graphics/Shape.hpp>
#include <SFML/System/Vector2.hpp>

class Iobject : public sf::Drawable {
protected:
    std::unique_ptr<sf::Shape> _shape;
    sf::Vector2f _position{0.0f, 0.0f};
    sf::Vector2f _velocity{0.0f, 0.0f};
    float _speed{0.0f};
public:
    Iobject() = default;
    virtual ~Iobject() override = default;
    virtual void update(float deltaTime, sf::RenderWindow &window) = 0;
    void draw(sf::RenderTarget &target, sf::RenderStates states) const override;
    void setSpeed(float speed) {_speed = speed;};
    void setPosition(sf::Vector2f position);
    void setVelocity(sf::Vector2f velocity) {_velocity = velocity;}
    float getSpeed() const {return _speed;}
    sf::Vector2f getPosition() const {return _position;}
    sf::Vector2f getVelocity() const {return _velocity;}
    sf::FloatRect getGlobalbounds() const { return _shape ? _shape->getGlobalBounds() : sf::FloatRect();}
};
