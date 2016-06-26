#pragma once

#include "BaseGame.h"
class BaseGame;

class GameState {
public:
    GameState(BaseGame *g);

    virtual void update() = 0;
    virtual void render() = 0;

protected:
    BaseGame *game;
};
