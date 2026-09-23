#include "Blockbreaker.hpp"

#include "Menu/Menu.hpp"

Blockbreaker::Blockbreaker() : _window(sf::VideoMode({800, 600}), "Blockbraker", sf::State::Windowed), _SceneManager()
{
    sf::Vector2u desktopSize = sf::VideoMode::getDesktopMode().size;
    sf::Vector2u windowSize = _window.getSize();
    int posX = static_cast<int>(desktopSize.x - windowSize.x) / 2;
    int posY = static_cast<int>(desktopSize.y - windowSize.y) / 2;
    _window.setPosition({posX, posY});
}

Blockbreaker::~Blockbreaker()
{
}

void Blockbreaker::run()
{
    sf::Clock Clock;
    _SceneManager.pushScene(std::make_unique<Menu>(_SceneManager, _window));
    _window.setFramerateLimit(60);
    while (_window.isOpen() && !_SceneManager.isEmpty()) {
        float time = Clock.restart().asSeconds();
        while (const std::optional event = _window.pollEvent()) {
            if (event->is<sf::Event::Closed>()) {
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
