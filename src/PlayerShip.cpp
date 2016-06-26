#include "PlayerShip.h"
#include "TextureList.h"

PlayerShip::PlayerShip()
{
    //ctor
}

PlayerShip::PlayerShip(int x, int y)
{
    p_x = x;
    p_y = y;
    sprite.setTexture(*textureList.getTexture(TextureID::shipPlayer));
}

PlayerShip::~PlayerShip()
{
    //dtor
}

void PlayerShip::draw(sf::RenderTarget& target, sf::RenderStates states) {

}
