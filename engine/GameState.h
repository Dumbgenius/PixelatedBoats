#pragma once

#include <vector>
#include "GameObject.h"

class BaseGame;

class GameState {
public:
    GameState(BaseGame *g);

    virtual void update() = 0;
    virtual void render() = 0;

    // These get called when switching states
    virtual void load() = 0;
    virtual void unload() = 0;

    std::vector<GameObject*> objectsList;

protected:
    BaseGame *game;
};
