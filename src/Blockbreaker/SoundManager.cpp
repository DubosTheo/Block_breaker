#include "SoundManager.hpp"

#include <SFML/Audio/Sound.hpp>

Sound SoundManager::addSound(std::string pathFile)
{
    auto soundBuffer = std::make_unique<sf::SoundBuffer>(pathFile);
    if (!soundBuffer)
        throw std::runtime_error("Can't load file sound");
    auto sound = std::make_unique<sf::Sound>(*soundBuffer);
    _soundBuffer.emplace_back(std::move(soundBuffer));
    _sound.emplace_back(std::move(sound));
    Sound id(_sound.size() -1);
    return id;
}

void SoundManager::playSound(Sound id) const
{
    _sound[id.getId()]->play();
}
