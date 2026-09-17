#pragma once
#include "Ball.hpp"
#include "Racket.hpp"
#include "Blockbreaker/Iscene.hpp"
#include "Blockbreaker/SceneManager.hpp"
#include <vector>
#include <memory>

#include "Brick.hpp"
#include "Sound.hpp"

class Game : public Iscene{
private:
    SceneManager &_sceneManager;
    sf::Clock _clock;
    std::vector<std::unique_ptr<ball>> _balls;
    racket _racket;
    std::vector<std::unique_ptr<Brick>> _bricks;
    sounds _sounds;
public:
    explicit Game(SceneManager &SceneManager, sf::RenderWindow &window);
    ~Game() override;
    void handleEvent(sf::RenderWindow &window) override;
    void update(float time, sf::RenderWindow &window) override;
    void draw(sf::RenderWindow &window) override;
    void checkRacketColision(ball &ball);
    void checkBrickColision(ball &ball);
    void checkBallWallColision(ball &ball, sf::RenderWindow &window);
};
