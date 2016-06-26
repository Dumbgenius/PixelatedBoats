#include "TextureList.h"

textureLocationByID[TextureID::shipPlayer] = "img/shipPlayer.png";

TextureList::TextureList()
{
    //ctor
}

const sf::Texture* TextureList::getTexture(TextureID textureID) {
    if (!texturesLoaded[textureID]) {
        bool loadSucceeded TextureList[textureID].loadFromFile(TextureLocationByID[textureID]);
        if (!loadSucceeded) {
            throw "Texture" + TextureLocationByID[textureID] + "failed to load.";
        }
    }
    const sf::Texture *result = &TextureList[textureID]
    return result;
}
