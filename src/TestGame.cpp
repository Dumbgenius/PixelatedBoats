#include "BaseGame.h"
#include "TestGame.h"

// Inter-state management should go here.

TestGame::TestGame(int wWidth, int wHeight) : BaseGame(wWidth, wHeight) {}

void TestGame::update() {
    currentState->update();

}
void TestGame::render() {
   currentState->render();
}
