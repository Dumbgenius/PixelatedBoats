#ifndef GAMEOBJECT_H
#define GAMEOBJECT_H

#include <SFML/Graphics.hpp>


class GameObject : public sf::Drawable
{
    public:
        GameObject();
        GameObject(float posx, float posy, float rotation);
        virtual void update(sf::Time elapsed) = 0;
    protected:
        float p_x;
        float p_y;
        float p_rotation;
};

#endif // GAMEOBJECT_H
