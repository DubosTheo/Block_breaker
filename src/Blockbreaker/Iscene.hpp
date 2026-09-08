#pragma once

class Iscene {
public:
    virtual ~Iscene() = default;
    virtual void handleEvent() = 0;
    virtual void update() = 0;
    virtual void draw() = 0;
};
