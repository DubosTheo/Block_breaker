#include "Game.hpp"

Game::Game(SceneManager &SceneManager, sf::RenderWindow &window) : _sceneManager(SceneManager), _racket(window.getSize())
{
    float x = 100;
    float y = 50;
    _balls.push_back(std::make_unique<ball>());
    for (int i = 0; i < 20; i++) {
        sf::Vector2f position;
        position.x = x;
        position.y = y;
        _bricks.push_back(std::make_unique<Brick>(position, window.getSize()));
        x += 200;
        if (x > window.getSize().x) {
            x = 100;
            y += 50;
        }
    }
}

Game::~Game()
{
}


void Game::draw(sf::RenderWindow &window)
{
    window.draw(_racket);
    for (const auto& balls : _balls) {
        if (balls)
            window.draw(*balls);
    }
    for (const auto& bricks : _bricks) {
        if (bricks)
            window.draw(*bricks);
    }
}

void Game::handleEvent(sf::RenderWindow &window)
{
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::Escape))
        window.close();
}

void Game::update(float time, sf::RenderWindow &window)
{
    _racket.update(time, window);
    for (auto& balls : _balls) {
        balls->update(time, window);
        checkRacketColision(*balls);
    }
}

void Game::checkRacketColision(ball &ball)
{
    if (ball.getGlobalbounds().findIntersection(_racket.getGlobalbounds())) {
        sf::Vector2f vel = ball.getVelocity();
        vel.y = -std::abs(vel.y); // Rebond vers le haut
        ball.setVelocity(vel);
    }
}



