#pragma once
#ifndef PLAYERSHIP_H
#define PLAYERSHIP_H

#include <SFML/Graphics.hpp>
#include "GameState.h"
#include "GameObject.h"

class PlayerShip : GameObject
{
    public:
        PlayerShip(GameState* gameState);
        PlayerShip(GameState* gameState, float x, float y);
        virtual ~PlayerShip();
        void draw(sf::RenderTarget& target, sf::RenderStates states) const;
        void update();
        void move(float x, float y);
        void move(float distance);
        void rotate(float degrees);
        sf::Vector2f getPosition();
    private:
        float p_x;
        float p_y;
        float p_rotation;
        float p_speed;
        float p_rotateSpeed;
        sf::Sprite p_sprite;
};

#endif // PLAYERSHIP_H
