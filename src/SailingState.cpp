#include "SailingState.h"

SailingState::SailingState(BaseGame *g) : GameState(g)
{
    //ctor
}

void SailingState::load(GameState *prevState) {
    player = new PlayerShip (this, 100, 100);
    view = game->getWindow()->getDefaultView();
}

void SailingState::unload() {
    delete player;
}

void SailingState::update(sf::Time elapsed) {
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

void SailingState::render() {
        sf::RenderWindow *wind = game->getWindow();
        view.setCenter(player->getPosition());
        wind->setView(view);
        wind->clear();
        for (unsigned int i=0; i<objectsList.size(); i++) {
            wind->draw(*objectsList[i]);
        }
        wind->display();
    }
