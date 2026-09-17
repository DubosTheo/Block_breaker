#pragma once
#include <SFML/Audio/Sound.hpp>
#include <SFML/Audio/SoundBuffer.hpp>

class sounds {
private:
    sf::SoundBuffer _bounceBallBuffer;
    sf::Sound _bounceBallSound;
    sf::SoundBuffer _destroyBrickBuffer;
    sf::Sound _destroyBrickSound;
public:
    sounds();
    ~sounds() = default;
    void playBounceBall();
    void playDestroyBrick();
};
