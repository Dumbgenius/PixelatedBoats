#include "TextureList.h"
#include <iostream>

int TextureID_LENGTH = 1;

std::map<int, std::string> textureLocationByID;

TextureList textureList;

TextureList::TextureList()
{
    textureLocationByID[TextureID::shipPlayer] = "img/shipPlayer.png";
}

sf::Texture* TextureList::getTexture(TextureID textureID) {
    if (!texturesLoaded[textureID]) {
        bool loadSucceeded = textureList.textures[textureID].loadFromFile(textureLocationByID[textureID]);
        if (!loadSucceeded) {
            throw "Texture" + textureLocationByID[textureID] + "failed to load.";
        } else {
            std::cout<<"Successfully loaded texture\""<<textureLocationByID[textureID]<<"\".";
        }
    }

    return &(textureList.textures[textureID]);
}
