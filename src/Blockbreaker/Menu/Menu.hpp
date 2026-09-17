#pragma once
#include "../Iscene.hpp"
#include "../SceneManager.hpp"

class Menu : public Iscene {
private:
    SceneManager &_SceneManager;
    sf::Font _font;
    std::vector<std::unique_ptr<sf::Text>> _text;
public:
    explicit Menu(SceneManager &SceneManager, sf::RenderWindow &window);
    ~Menu() override;
    void handleEvent(sf::RenderWindow &window) override;
    void update(float time, sf::RenderWindow &window) override;
    void draw(sf::RenderWindow &window) override;
};
