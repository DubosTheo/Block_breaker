/*
** EPITECH PROJECT, 2026
** Block_breaker
** File description:
** Blockbreaker
*/
#include "Blockbreaker.hpp"

Blockbreaker::Blockbreaker() : _game(), _window(sf::VideoMode({800, 600}), "Blockbraker")
{
}

Blockbreaker::~Blockbreaker()
{
}

void Blockbreaker::run()
{
    while (_window.isOpen()) {
        while (_window.pollEvent(_event))
            if( _event.type == sf::Event::Closed)
            _window.close();
        _window.clear(sf::Color::Black);
        _window.display();
    }
}
