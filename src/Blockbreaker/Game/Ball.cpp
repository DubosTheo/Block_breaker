#include "Ball.hpp"

#include <cmath>

ball::ball() : _circle_shape(10), _position(500, 400), _velocity(0.707f, -0.707f), _speed(200)
{
    float radius = _circle_shape.getRadius();
    _circle_shape.setFillColor(sf::Color::Black);
    _circle_shape.setOutlineColor(sf::Color::Green);
    _circle_shape.setOutlineThickness(2);
    _circle_shape.setOrigin(radius, radius);
}

static void checkScreenCollision(sf::Vector2f& pos, sf::Vector2f& vel, float radius,
    const sf::Vector2u& windowSize, sf::RenderWindow &window)
{
    if (pos.x - radius <= 0.0f) {
        vel.x = std::abs(vel.x);
        pos.x = radius;
    }
    else if (pos.x + radius >= windowSize.x) {
        vel.x = -std::abs(vel.x);
        pos.x = windowSize.x - radius;
    }
    if (pos.y - radius <= 0.0f) {
        vel.y = std::abs(vel.y);
        pos.y = radius;
    }
    else if (pos.y + radius >= windowSize.y)
        window.close();
}


static bool checkRacketCollision(sf::Vector2f& ballPos, sf::Vector2f& ballVel, float radius,
                                 const sf::Vector2f& racketPos, const sf::Vector2f& racketSize)
{
    float rLeft   = racketPos.x - racketSize.x / 2.0f;
    float rRight  = racketPos.x + racketSize.x / 2.0f;
    float rTop    = racketPos.y - racketSize.y / 2.0f;
    float rBottom = racketPos.y + racketSize.y / 2.0f;

    float closestX = std::clamp(ballPos.x, rLeft, rRight);
    float closestY = std::clamp(ballPos.y, rTop, rBottom);

    float distX = ballPos.x - closestX;
    float distY = ballPos.y - closestY;
    float distanceSq = (distX * distX) + (distY * distY);

    if (distanceSq < (radius * radius)) {
        ballPos.y = rTop - radius;
        float hitFactor = (ballPos.x - racketPos.x) / (racketSize.x / 2.0f);
        hitFactor = std::clamp(hitFactor, -1.0f, 1.0f);
        ballVel.x = hitFactor;
        ballVel.y = -std::abs(ballVel.y);
        float length = std::sqrt(ballVel.x * ballVel.x + ballVel.y * ballVel.y);
        if (length != 0.0f) {
            ballVel /= length;
        }
        return true;
    }
    return false;
}

void ball::update(float dt, sf::RenderWindow &window, const racket& racket)
{
    _position += _velocity * _speed * dt;

    float radius = _circle_shape.getRadius();

    checkScreenCollision(_position, _velocity, radius, window.getSize(), window);
    checkRacketCollision(_position, _velocity, radius,
        racket.getPosition(), sf::Vector2f(100.0f, 20.0f));
    _circle_shape.setPosition(_position);
}


void ball::draw(sf::RenderWindow &window) const
{
    window.draw(_circle_shape);
}


void ball::setPosition(const sf::Vector2f position)
{
    _position = position;
}

void ball::setSpeed(const float speed)
{
    _speed = speed;
}

void ball::setVelocity(const sf::Vector2f velocity)
{
    _velocity = velocity;
}

