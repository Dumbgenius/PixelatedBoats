#pragma once
#include <SFML/Graphics.hpp>
#include "BaseGame.h"

class TestGame : public BaseGame {
public:
    TestGame(int wWidth, int wHeight);

    void update();
    void render();
};
