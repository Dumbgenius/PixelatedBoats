#include "PlayerShip.h"
#include "TextureList.h"
#include <math.h>
#include <iostream>

const float PI = 3.14159265;

PlayerShip::PlayerShip(GameState* gameState) {
    // Call other constructor, save time
    PlayerShip(gameState, 0, 0);
}

PlayerShip::PlayerShip(GameState* gameState, float x, float y) : GameObject(x, y, 0) {
    p_x = x;
    p_y = y;
    p_rotation = 0;
    p_speed = 60; //in pixels per second
    p_rotateSpeed = 30; //in degrees per second
    textureList.getTexture(TextureID::shipPlayer)->setSmooth(true);
    p_sprite.setTexture(TextureID::shipPlayer);
    p_sprite.setPosition(p_x, p_y);
    p_sprite.setRotation(p_rotation);
    p_sprite.setOrigin(64,64);
    setRect(p_sprite.getGlobalBounds());
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

void PlayerShip::move(float distance) {
    p_x -= sin(-p_rotation/(180/PI)) * distance;
    p_y -= cos(-p_rotation/(180/PI)) * distance;
    p_sprite.setPosition(p_x, p_y);
}

void PlayerShip::rotate(float degrees) {
    p_sprite.rotate(degrees);
    p_rotation = p_sprite.getRotation();
}

void PlayerShip::update(sf::Time elapsed) {
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Left) && !sf::Keyboard::isKeyPressed(sf::Keyboard::Right)) {
        if (sf::Keyboard::isKeyPressed(sf::Keyboard::Down) && !sf::Keyboard::isKeyPressed(sf::Keyboard::Up)) {
            rotate(p_rotateSpeed * elapsed.asSeconds());
        } else {
            rotate(-p_rotateSpeed * elapsed.asSeconds());
        }
    }
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Right) && !sf::Keyboard::isKeyPressed(sf::Keyboard::Left)) {
        if (sf::Keyboard::isKeyPressed(sf::Keyboard::Down) && !sf::Keyboard::isKeyPressed(sf::Keyboard::Up)) {
            rotate(-p_rotateSpeed * elapsed.asSeconds());
        } else {
            rotate(p_rotateSpeed * elapsed.asSeconds());
        }
    }
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Up) && !sf::Keyboard::isKeyPressed(sf::Keyboard::Down)) {
        move(p_speed * elapsed.asSeconds());
    }
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Down) && !sf::Keyboard::isKeyPressed(sf::Keyboard::Up)) {
        move(-p_speed * elapsed.asSeconds());
    }
}

void PlayerShip::draw(sf::RenderTarget& target, sf::RenderStates states) const {
    target.draw(p_sprite, states);
}

sf::Vector2f PlayerShip::getPosition() {
    return p_sprite.getPosition();
}

