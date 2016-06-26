#pragma once
#include <SFML/Graphics.hpp>
#include "EGraphics.h"
#include "GameState.h"

class BaseGame {
public:
    BaseGame(int wWidth, int wHeight);

    virtual void update() = 0;
    virtual void render() = 0;

    sf::RenderWindow *getWindow();
    void changeState(GameState *state);

    EGraphics *gfx;

protected:
    GameState *currentState;
};
