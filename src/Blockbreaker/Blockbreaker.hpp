#pragma once

#include "Game/Game.hpp"
#include <SFML/Graphics.hpp>

#include "SceneManager.hpp"

class Blockbreaker {
private:
    sf::RenderWindow _window;
    SceneManager _SceneManager;
public:
    Blockbreaker();
    ~Blockbreaker();
    void run();
};

