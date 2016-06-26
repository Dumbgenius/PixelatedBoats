#include <SFML/Graphics.hpp>
#include "TestGame.h"
#include "BaseGame.h"
#include "GameState.h"
#include "PlayerShip.h"

class TestState : GameState {
public:
    TestState(BaseGame *g) : GameState(g) {
        PlayerShip *playerShip = new PlayerShip (100, 100);
    }
    void update() {
        sf::RenderWindow *wind = game->getWindow();
        sf::Event ev;

        while (wind->pollEvent(ev))
            if (ev.type == sf::Event::Closed)
                wind->close();
    }

    void render() {
        sf::RenderWindow *wind = game->getWindow();
        wind->clear();
        wind->display();
    }
};

int main() {

    TestGame tGame = TestGame(1000, 500);
    TestState tState = TestState(&tGame);

    tGame.changeState((GameState *)&tState);

    sf::RenderWindow *wind = tGame.getWindow();

    while (wind->isOpen()) {
        tGame.update();
        tGame.render();
    }

    return 0;
}
