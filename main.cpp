#include <SFML/Graphics.hpp>
#include "TestGame.h"
#include "BaseGame.h"
#include "GameState.h"
#include "PlayerShip.h"
#include <iostream>

class TestState : GameState {
public:
    TestState(BaseGame *g) : GameState(g) {}

    void load(GameState *prevState) {
        player = new PlayerShip (this, 100, 100);
        view = game->getWindow()->getDefaultView();
    }
    void unload() {
        delete player;
    }

    sf::View view;
    PlayerShip* player;

    void update(sf::Time elapsed) {
        sf::RenderWindow *wind = game->getWindow();
        sf::Event ev;

        while (wind->pollEvent(ev)) {
            if (ev.type == sf::Event::Closed) {
                wind->close();
            }
        }

        for (unsigned int i=0; i<objectsList.size(); i++) {
            objectsList[i]->update(elapsed);
        }
    }

    void render() {
        sf::RenderWindow *wind = game->getWindow();
        wind->setView(view);
        wind->clear();
        view.setCenter(player->getPosition());
        for (unsigned int i=0; i<objectsList.size(); i++) {
            wind->draw(*objectsList[i]);
        }
        wind->display();
    }
};

int main() {

    TestGame tGame = TestGame(1000, 500);
    TestState tState = TestState(&tGame);

    tGame.changeState((GameState *)&tState);

    sf::RenderWindow *wind = tGame.getWindow();

    wind->setFramerateLimit(60);

    sf::Clock gameClock;
    while (wind->isOpen()) {
        tGame.update(gameClock.restart());
        tGame.render();
    }

    return 0;
}
