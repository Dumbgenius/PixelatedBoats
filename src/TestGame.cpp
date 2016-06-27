#include "BaseGame.h"
#include "TestGame.h"
#include <SFML/Graphics.hpp>

// Inter-state management should go here.

TestGame::TestGame(int wWidth, int wHeight) : BaseGame(wWidth, wHeight) {}

void TestGame::update(sf::Time elapsed) {
    currentState->update(elapsed);

}
void TestGame::render() {
   currentState->render();
}
