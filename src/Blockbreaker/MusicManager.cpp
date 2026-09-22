#include "MusicManager.hpp"

Music MusicManager::addMusic(std::string pathFile)
{
    auto music = std::make_unique<sf::Music>(pathFile);
    if (!music)
        throw std::runtime_error("Can't load file");
    _music.emplace_back(std::move(music));
    Music id(_music.size() - 1);
    return id;
}

void MusicManager::playMusic(Music music) const
{
    size_t id = music.getId();
    _music[id]->setLooping(true);
    _music[id]->play();
}

