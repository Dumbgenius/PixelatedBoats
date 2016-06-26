#include "PlayerShip.h"
#include "TextureList.h"

PlayerShip::PlayerShip(GameState* gameState) {
    p_x = 0;
    p_y = 0;
    p_sprite.setTexture(*textureList.getTexture(TextureID::shipPlayer));
    p_sprite.setPosition(p_x, p_y);
    gameState->objectsList.insert(gameState->objectsList.end(), this);
}

PlayerShip::PlayerShip(GameState* gameState, float x, float y) {
    p_x = x;
    p_y = y;
    p_sprite.setTexture(*textureList.getTexture(TextureID::shipPlayer));
    p_sprite.setPosition(p_x, p_y);
    gameState->objectsList.insert(gameState->objectsList.end(), this);
}

PlayerShip::~PlayerShip() {
    //dtor
}

void PlayerShip::move(float x, float y) {
    p_x += x;
    p_y += y;
    p_sprite.setPosition(p_x, p_y);
}

void PlayerShip::update() {
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Left) && !sf::Keyboard::isKeyPressed(sf::Keyboard::Right)) {
        move(-1, 0);
    }
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Right) && !sf::Keyboard::isKeyPressed(sf::Keyboard::Left)) {
        move(1, 0);
    }
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Up) && !sf::Keyboard::isKeyPressed(sf::Keyboard::Down)) {
        move(0, -1);
    }
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Down) && !sf::Keyboard::isKeyPressed(sf::Keyboard::Up)) {
        move(0, 1);
    }
}

void PlayerShip::draw(sf::RenderTarget& target, sf::RenderStates states) const {
    target.draw(p_sprite, states);
}
