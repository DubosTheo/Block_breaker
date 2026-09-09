#pragma once
#include <memory>
#include <vector>
#include <SFML/Graphics.hpp>

#include "Iscene.hpp"

class SceneManager {
private:
    std::vector<std::unique_ptr<Iscene>> _SceneManager;
public:
    SceneManager() = default;
    ~SceneManager() = default;

    void pushScene(std::unique_ptr<Iscene> newScene);
    void changeScene(std::unique_ptr<Iscene> newScene);
    void popScene();
    void draw(sf::RenderWindow &window);
    void update(float time, sf::RenderWindow &window);
    void handleEvents(sf::RenderWindow &window);
    bool isEmpty() const {return _SceneManager.empty();}
};
