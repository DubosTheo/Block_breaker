#pragma once
#include <memory>
#include <vector>
#include <SFML/Audio/Music.hpp>

#include "Music.hpp"

class MusicManager {
private:
    std::vector<std::unique_ptr<sf::Music>> _music;
public:
    Music addMusic(std::string pathFile);
    void playMusic(Music music) const;
};
