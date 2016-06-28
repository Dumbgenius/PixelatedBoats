#ifndef SAILINGSTATE_H
#define SAILINGSTATE_H

#include "GameState.h"
#include "PlayerShip.h"
#include "BaseGame.h"

class SailingState : GameState {
    public:
        SailingState(BaseGame *g);

        void load(GameState *prevState);
        void unload();

        sf::View view;
        PlayerShip* player;

        void update(sf::Time elapsed);

        void render();
    private:
        sf::Font font;
};

#endif // SAILINGSTATE_H
