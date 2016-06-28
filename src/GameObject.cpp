#include "GameObject.h"

GameObject::GameObject() {
    //ctor
}

GameObject::GameObject(float posx, float posy, float rotation) {
    p_x = posx;
    p_y = posy;
    p_rotation = 0;
    p_rect = sf::Rect<float>(p_x, p_y, 0, 0);
}

sf::Rect<float> GameObject::getRect() {
    return p_rect;
}

void GameObject::setRect(sf::Rect<float> r) {
    p_rect.left = r.left;
    p_rect.top = r.top;
    p_rect.width = r.width;
    p_rect.height = r.height;
}
