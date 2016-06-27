#include <SFML/Graphics.hpp>
#include <iostream>
#include "TestGame.h"
#include "BaseGame.h"
#include "GameState.h"
#include "PlayerShip.h"
#include "GameState.h"
#include "SailingState.h"

int main() {

    TestGame game = TestGame(1000, 500);
    SailingState state = SailingState(&game);

    game.changeState((GameState *)&state);

    sf::RenderWindow *wind = game.getWindow();

    wind->setFramerateLimit(60);

    sf::Clock gameClock;
    sf::Event ev;

    while (wind->isOpen()) {
        while (wind->pollEvent(ev)) {
            if (ev.type == sf::Event::Closed) {
                wind->close();
            }
        }
        game.update(gameClock.restart());
        game.render();
    }

    return 0;
}
