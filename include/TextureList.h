#ifndef TEXTURELIST_H
#define TEXTURELIST_H

#include <SFML/Graphics.hpp>
#include <array>
#include <map>
#include <string>

enum TextureID {
    shipPlayer = 0
};

int TextureID_LENGTH = 1;

std::map<int, std::string> textureLocationByID;

class TextureList
{
    public:
        TextureList();
        const sf::Texture* getTexture(TextureID textureID);
    private:
        std::array<sf::Texture, 1> textures;
        std::array<bool, 1> texturesLoaded;
};

TextureList textureList; //this is supposed to be a constant texture list. hopefully.

#endif // TEXTURELIST_H