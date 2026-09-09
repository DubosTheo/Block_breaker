#pragma once
#include "Ball.hpp"
#include "Racket.hpp"
#include "Blockbreaker/Iscene.hpp"
#include "Blockbreaker/SceneManager.hpp"

class Game : public Iscene{
private:
    SceneManager &_SceneManager;
    sf::Clock _clock;
    std::vector<ball> _balls;
    std::unique_ptr<racket> _racket;
public:
    explicit Game(SceneManager &SceneManager, sf::RenderWindow &window);
    ~Game() override;
    void handleEvent(sf::RenderWindow &window) override;
    void update(float time, sf::RenderWindow &window) override;
    void draw(sf::RenderWindow &window) override;

};
