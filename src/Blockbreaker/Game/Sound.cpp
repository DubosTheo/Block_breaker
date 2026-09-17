#include "Sound.hpp"

sounds::sounds() : _bounceBallSound(_bounceBallBuffer), _destroyBrickSound(_destroyBrickBuffer)
{
    if (!_bounceBallBuffer.loadFromFile("assets/Sound/ball_bounce.mp3"))
        throw std::runtime_error("Can't load sound : assets/Sound/ball_bounce.mp3");
    if (!_destroyBrickBuffer.loadFromFile("assets/Sound/Brick_destruct.mp3"))
        throw std::runtime_error("Can't load sound : assets/Sound/Brick_destruct.mp3");
}

void sounds::playBounceBall()
{
    _bounceBallSound.play();
}

void sounds::playDestroyBrick()
{
    _destroyBrickSound.play();
}


