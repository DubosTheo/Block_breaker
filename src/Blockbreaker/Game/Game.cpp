#include "Game.hpp"

Game::Game(SceneManager &SceneManager, sf::RenderWindow &window) : _sceneManager(SceneManager), _racket(window.getSize())
{
    _balls.push_back(std::make_unique<ball>());
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
}

void Game::handleEvent(sf::RenderWindow &window)
{
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Escape))
        window.close();
}

void Game::update(float time, sf::RenderWindow &window)
{
    _racket.update(time, window);
    for (auto& balls : _balls)
        balls->update(time, window);
}


