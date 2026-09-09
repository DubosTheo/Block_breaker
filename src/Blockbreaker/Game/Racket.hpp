#pragma once
#include <SFML/Graphics/RectangleShape.hpp>
#include <SFML/Graphics/RenderWindow.hpp>
#include <SFML/System/Thread.hpp>

class racket {
private:
    sf::RectangleShape _rectShape;
    sf::Vector2f _position;
    sf::Vector2f _velocity;
    float _speed;
public:
    explicit racket(const sf::Vector2u& windowSize);
    ~racket() = default;
    void setPosition(const sf::Vector2f position);
    void setVelocity(const sf::Vector2f velocity);
    void setSpeed(const float speed);
    sf::Vector2f getPosition() const {return _position;}
    sf::Vector2f getVelocity() const { return _velocity;}
    float getspeed() const {return _speed;}
    void update(float dt, sf::RenderWindow &window);
    void draw(sf::RenderWindow& window) const;
};
