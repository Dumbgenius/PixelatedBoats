#include "EGraphics.h"
#include "BaseGame.h"

BaseGame::BaseGame(int wWidth, int wHeight) {
    gfx = new EGraphics(wWidth, wHeight);
    currentState = 0;
}

sf::RenderWindow *BaseGame::getWindow() {
    return gfx->getWindow();
}

void BaseGame::changeState(GameState *state) {
    GameState *prevState = currentState;
    if (currentState != NULL) currentState->unload();
    currentState = state;
    currentState->load(prevState);
}
