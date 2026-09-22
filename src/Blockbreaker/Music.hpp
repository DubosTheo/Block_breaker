#pragma once

#include "cstddef"

class Music {
private:
    size_t _id;
public:
    Music(size_t id) : _id(id){}
    size_t getId() const {return _id;}
};
