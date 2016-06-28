#include "SailingState.h"
#include <sstream>

SailingState::SailingState(BaseGame *g) : GameState(g)
{
    load(nullptr);
}

void SailingState::load(GameState *prevState) {
    font.loadFromFile("resources/font.ttf");
    player = new PlayerShip (this, 100, 100);
    view = game->getWindow()->getDefaultView();
}

void SailingState::unload() {
    delete player;
}

void SailingState::update(sf::Time elapsed) {
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
        if (DEBUG) {
            std::stringstream debugString;
            debugString << "X: " << player->getPosition().x << "\nY: " << player->getPosition().y;
            sf::Text debugText (debugString.str(), font, 16);
            debugText.setPosition((sf::Vector2f)wind->mapPixelToCoords(sf::Vector2i(10, 10), view));
            wind->draw(debugText);
        }

        wind->display();
    }
