#ifndef GAMEOBJECT_H
#define GAMEOBJECT_H

#include <SFML/Graphics.hpp>


class GameObject : public sf::Drawable
{
    public:
        GameObject();
        virtual void update(sf::Time elapsed) = 0;
};

#endif // GAMEOBJECT_H
