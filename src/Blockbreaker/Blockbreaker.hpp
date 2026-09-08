#pragma once

#include "Game/Game.hpp"
#include <SFML/Graphics.hpp>
class Blockbreaker {
private:
    sf::RenderWindow _window;
    sf::Event _event;
public:
    Blockbreaker();
    ~Blockbreaker();
    void run();
};

