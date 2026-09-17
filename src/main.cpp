/*
** EPITECH PROJECT, 2026
** Block_breaker
** File description:
** main
*/

#include <iostream>

#include "Blockbreaker/Blockbreaker.hpp"

int main()
{
   Blockbreaker blockbreaker;

    try {
        blockbreaker.run();
    }
    catch (std::out_of_range &o) {
        std::cerr << o.what() << std::endl;
    }
    catch (std::exception& e) {
        std::cerr << e.what() << std::endl;
    }
    return 0;
}
