#pragma once
#include <cstddef>

class SoundManager;

class Sound {
private:
    size_t _id;
public:
    explicit Sound(size_t id) :  _id(id){}
    [[nodiscard]] size_t getId() const {return _id;}
};
