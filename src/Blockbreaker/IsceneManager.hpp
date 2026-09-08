#pragma once
#include <memory>
#include <vector>

#include "Iscene.hpp"

class IsceneManager {
private:
    std::vector<std::unique_ptr<Iscene>> _Iscene;
public:



};
