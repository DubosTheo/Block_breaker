#include "Menu.hpp"

#include "../Game/Game.hpp"

Menu::~Menu()
{
}


void Menu::handleEvent(sf::RenderWindow &window)
{
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::Enter))
        _SceneManager.changeScene(std::make_unique<Game>(_SceneManager, window));
}

Menu::Menu(SceneManager &SceneManager, sf::RenderWindow &window) : _SceneManager(
    SceneManager), _menu(0)
{
    if (!_font.openFromFile("assets/fonts/ARCADECLASSIC.TTF"))
        throw std::runtime_error(
            "Can't load font : assets/fonts/ARCADECLASSIC.TTF");
    auto text = std::make_unique<sf::Text>(_font, "Play", 50);
    text->setFillColor(sf::Color::White);
    text->setStyle(sf::Text::Bold);
    text->setPosition({
        window.getSize().x / 2.0f - 50, window.getSize().y / 2.0f - 50
    });
    _text.push_back(std::move(text));
    _menu = _musicManager.addMusic("assets/Musics/menu.mp3");
    _musicManager.playMusic(_menu);
}

void Menu::update(float time, sf::RenderWindow &window)
{
}

void Menu::draw(sf::RenderWindow &window)
{
    for (const auto& texts : _text) {
        window.draw(*texts);
    }
}
