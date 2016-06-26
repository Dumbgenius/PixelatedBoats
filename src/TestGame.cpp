#include "../engine/BaseGame.hpp"
#include "TestGame.hpp"

TestGame::TestGame(int wWidth, int wHeight) : BaseGame(wWidth, wHeight) {}

void TestGame::update() {
    currentState->update();

}
void TestGame::render() {
   currentState->render();
}
