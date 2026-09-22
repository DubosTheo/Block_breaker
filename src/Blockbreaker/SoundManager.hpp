#pragma once

#include <cstddef>
#include <string>
#include <vector>
#include <SFML/Audio/SoundBuffer.hpp>
#include "Sound.hpp"

class SoundManager{
private:
    std::vector<std::unique_ptr<sf::SoundBuffer>> _soundBuffer;
    std::vector<std::unique_ptr<sf::Sound>> _sound;
public:
    ~SoundManager() = default;
    Sound addSound(std::string pathFile);
    void playSound(Sound id) const;
};
