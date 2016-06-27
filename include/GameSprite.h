#ifndef GAMESPRITE_H
#define GAMESPRITE_H

#include <SFML/Graphics.hpp>

#include "TextureList.h"


class GameSprite : public sf::Sprite
{
    public:
        GameSprite();
        GameSprite(TextureID textureID);
        ~GameSprite();

        void setTexture(TextureID textureID, bool resetRect = false);
    private:
        void setTexture(const sf::Texture& texture, bool resetRect = false);
        int currentTextureID;
};

#endif // GAMESPRITE_H
