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
    _SceneManager.pushScene(std::make_unique<Game>(_SceneManager, _window));
    float time = Clock.restart().asSeconds();
    _window.setFramerateLimit(60);
    while (_window.isOpen() && !_SceneManager.isEmpty()) {
        sf::Event event{};
        while (_window.pollEvent(event)) {
            if (event.type == sf::Event::Closed) {
                _window.close();
                break;
            }
        }
        _window.clear(sf::Color::Black);
        _SceneManager.handleEvents(_window);
        _SceneManager.update(time, _window);
        _SceneManager.draw(_window);
        _window.display();
    }
}
