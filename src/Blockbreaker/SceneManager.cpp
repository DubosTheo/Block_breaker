#include "SceneManager.hpp"

void SceneManager::pushScene(std::unique_ptr<Iscene> newScene)
{
    _SceneManager.push_back(std::move(newScene));
}

void SceneManager::popScene()
{
    if (!_SceneManager.empty())
        _SceneManager.pop_back();
}

void SceneManager::changeScene(std::unique_ptr<Iscene> newScene)
{
    if (!_SceneManager.empty()) {
        _SceneManager.pop_back();
    }
    pushScene(std::move(newScene));
}

void SceneManager::draw(sf::RenderWindow &window)
{
    if (!_SceneManager.empty())
        _SceneManager.back()->draw(window);
}

void SceneManager::handleEvents(sf::RenderWindow &window)
{
    if (!_SceneManager.empty())
        _SceneManager.back()->handleEvent(window);
}

void SceneManager::update(float time)
{
    if (!_SceneManager.empty())
        _SceneManager.back()->update(time);
}



