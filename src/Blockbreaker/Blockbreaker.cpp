#include "Blockbreaker.hpp"

Blockbreaker::Blockbreaker() : _window(sf::VideoMode({800, 600}), "Blockbraker"), _SceneManager()
{
}

Blockbreaker::~Blockbreaker()
{
}

void Blockbreaker::run()
{
    sf::Clock Clock;
    float time = Clock.restart().asSeconds();
    while (_window.isOpen() && !_SceneManager.isEmpty()) {
        _SceneManager.handleEvents(_window);
        _SceneManager.update(time);
        _SceneManager.draw(_window);
    }
}
