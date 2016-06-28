#ifndef GAMEOBJECT_H
#define GAMEOBJECT_H

#include <SFML/Graphics.hpp>
#include <SFML/Graphics/Rect.hpp>


class GameObject : public sf::Drawable
{
    public:
        GameObject();
        GameObject(float posx, float posy, float rotation);
        virtual void update(sf::Time elapsed) = 0;

        sf::Rect<float> getRect();
        void setRect(sf::Rect<float> r);
    protected:
        float p_x;
        float p_y;
        float p_rotation;
        sf::Rect<float> p_rect;
};

#endif // GAMEOBJECT_H
