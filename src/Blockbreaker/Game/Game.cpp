#include "Game.hpp"

Game::Game(SceneManager &SceneManager, sf::RenderWindow &window) : _sceneManager(
        SceneManager), _racket(window.getSize()), _gameMusic(0),
    _destroyBrick(0), _bounceBall(0)
{
    float x = 100;
    float y = 50;
    _balls.push_back(std::make_unique<ball>());
    for (int i = 0; i < 20; i++) {
        sf::Vector2f position;
        position.x = x;
        position.y = y;
        _bricks.push_back(std::make_unique<Brick>(position, window.getSize()));
        x += 200;
        if (x > window.getSize().x) {
            x = 100;
            y += 50;
        }
    }
    _destroyBrick = _soundManager.addSound("assets/Sound/Brick_destruct.mp3");
    _bounceBall = _soundManager.addSound("assets/Sound/ball_bounce.mp3");
    _gameMusic = _musicManager.addMusic("assets/Musics/game.mp3");
    _musicManager.playMusic(_gameMusic);
}

Game::~Game()
{
}

void Game::draw(sf::RenderWindow &window)
{
    window.draw(_racket);
    for (const auto& balls : _balls) {
        if (balls)
            window.draw(*balls);
    }
    for (const auto& bricks : _bricks) {
        if (bricks)
            window.draw(*bricks);
    }
}

void Game::handleEvent(sf::RenderWindow &window)
{
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::Escape))
        window.close();
}

void Game::update(float time, sf::RenderWindow &window)
{
    _racket.update(time, window);
    for (auto& balls : _balls) {
        balls->update(time, window);
        checkRacketColision(*balls);
        checkBrickColision(*balls);
        checkBallWallColision(*balls, window);
        if (_bricks.empty())
            window.close();
    }
}

void Game::checkRacketColision(ball &ball)
{
    sf::FloatRect ballBounds = ball.getGlobalbounds();
    sf::FloatRect racketBounds = _racket.getGlobalbounds();

    if (ballBounds.findIntersection(racketBounds)) {
        float racketCenterX = racketBounds.position.x + (racketBounds.size.x / 2.0f);
        float ballCenterX   = ballBounds.position.x + (ballBounds.size.x / 2.0f);
        float halfRacketWidth = racketBounds.size.x / 2.0f;
        float hitFactor = (ballCenterX - racketCenterX) / halfRacketWidth;
        sf::Vector2f vel = ball.getVelocity();
        vel.x = hitFactor * std::abs(vel.y);
        vel.y = -std::abs(vel.y);
        ball.setVelocity(vel);
        _soundManager.playSound(_bounceBall);
    }
}

void Game::checkBrickColision(ball &ball)
{
    for (auto i = _bricks.begin(); i != _bricks.end();) {
        if (*i && ball.getGlobalbounds().findIntersection((*i)->getGlobalbounds())) {
            sf::Vector2f vel = ball.getVelocity();
            sf::FloatRect ballBounds = ball.getGlobalbounds();
            sf::FloatRect brickBounds = (*i)->getGlobalbounds();
            auto intersection = ballBounds.findIntersection(brickBounds);
            if (intersection.has_value()) {
                if (intersection->size.x > intersection->size.y)
                    vel.y = -vel.y;
                else
                    vel.x = -vel.x;
            }
            else
                vel.y = -vel.y;
            ball.setVelocity(vel);
            _soundManager.playSound(_destroyBrick);
            i = _bricks.erase(i);
            break;
        } else
            ++i;
    }
}

void Game::checkBallWallColision(ball &ball, sf::RenderWindow &window)
{
    sf::Vector2f position = ball.getPosition();
    sf::Vector2f velocity = ball.getVelocity();
    float radius = ball.getRadius();
    if (position.x - radius < 0.0f || position.x + radius > window.getSize().x) {
        velocity.x = -velocity.x;
        _soundManager.playSound(_bounceBall);
    }
    if (position.y - radius < 0.0f) {
        velocity.y = -velocity.y;
        _soundManager.playSound(_bounceBall);
    }
    if (position.y + radius > window.getSize().y)
        window.close();
    ball.setVelocity(velocity);
    ball.setPosition(position);
}





