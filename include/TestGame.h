#pragma once
#include <SFML/Graphics.hpp>
#include "../engine/BaseGame.hpp"

class TestGame : public BaseGame {
public:
    TestGame(int wWidth, int wHeight);

    void update();
    void render();
};
