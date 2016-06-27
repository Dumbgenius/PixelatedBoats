#pragma once
#include "BaseGame.h"
#include <SFML/Graphics.hpp>

class TestGame : public BaseGame {
public:
    TestGame(int wWidth, int wHeight);

    void update(sf::Time elapsed);
    void render();
};
