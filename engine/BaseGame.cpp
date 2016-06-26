#include "EGraphics.hpp"
#include "BaseGame.hpp"

BaseGame::BaseGame(int wWidth, int wHeight) {
    gfx = new EGraphics(wWidth, wHeight);
    currentState = 0;
}

sf::RenderWindow *BaseGame::getWindow() {
    return gfx->getWindow();
}

void BaseGame::changeState(GameState *state) {
    currentState = state;
}