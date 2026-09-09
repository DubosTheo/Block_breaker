/*
** EPITECH PROJECT, 2026
** Block_breaker
** File description:
** Game
*/

#include "Game.hpp"

Game::Game(SceneManager &SceneManager, sf::RenderWindow &window) : _SceneManager(SceneManager)
{
    ball ball;
    _balls.push_back(ball);
}


void Game::draw(sf::RenderWindow &window)
{
    for (const auto& ball: _balls) {
        ball.draw(window);
    }
}

void Game::update(float time, sf::RenderWindow &window)
{
    float dt = _clock.restart().asSeconds();
    if (dt > 0.1f) {
        dt = 0.1f;
    }
    for (auto& ball : _balls) {
        ball.update(dt, window);
    }
}

Game::~Game()
{
}

void Game::handleEvent(sf::RenderWindow &window)
{
}


