/*
** EPITECH PROJECT, 2026
** Block_breaker
** File description:
** Game
*/

#ifndef BLOCK_BREAKER_GAME_HPP
#define BLOCK_BREAKER_GAME_HPP
#include <vector>

#include "Racket.hpp"

class Game {
private:
    std::vector<Racket> _racket;
public:
    Game();
};

#endif //BLOCK_BREAKER_GAME_HPP
