#include "TextureList.h"
#include <iostream>


TextureList textureList;

TextureList::TextureList()
{
    textures.push_back(TextureItem("resources/img/shipPlayer.png"));
    textures.push_back(TextureItem("resources/img/sea1.png"));
}

sf::Texture* TextureList::getTexture(int textureID) {
    if (!textures[textureID].isLoaded) {
        if (DEBUG) {std::cout<<"Loading texture'"<<textures[textureID].path<<"'... ";}
        bool loadSucceeded = textures[textureID].texture.loadFromFile(textures[textureID].path);
        if (!loadSucceeded) {
            std::cout<<"Texture '"<<textures[textureID].path<<"' failed to load.";
            throw "Texture" + textures[textureID].path + "failed to load.";
        } else {
            if (DEBUG) {std::cout<<"Success.\n";}
        }
        textures[textureID].isLoaded = true;
    }

    return &(textures[textureID].texture);
}

void TextureList::usingTexture(int textureID) {
    textures[textureID].noUsing++;
}

void TextureList::notUsingTexture(int textureID) {
    textures[textureID].noUsing--;
    if (textures[textureID].noUsing == 0) {
        unloadTexture(textureID);
    }
}

void TextureList::unloadTexture(int textureID) {
    textures[textureID].isLoaded = false;
    textures[textureID].texture = sf::Texture();
}
