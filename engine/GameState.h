#pragma once

#include <vector>
#include <SFML/Graphics.hpp>
#include "GameObject.h"

class BaseGame;

class GameState {
public:
    GameState(BaseGame *g);

    virtual void update(sf::Time elapsed) = 0;
    virtual void render() = 0;

    // These get called when switching states
    virtual void load(GameState *prevState) = 0;
    virtual void unload() = 0;

    std::vector<GameObject*> objectsList;

protected:
    BaseGame *game;
};
