#ifndef PLAYERSHIP_H
#define PLAYERSHIP_H

#include <SFML/Graphics.hpp>

class PlayerShip : sf::Drawable
{
    public:
        PlayerShip();
        PlayerShip(int x, int y);
        virtual ~PlayerShip();
        void draw(sf::RenderTarget& target, sf::RenderStates states);
    private:
        int p_x;
        int p_y;
        sf::Sprite sprite;
};

#endif // PLAYERSHIP_H
