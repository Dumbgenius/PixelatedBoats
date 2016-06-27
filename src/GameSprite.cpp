#include "GameSprite.h"

GameSprite::GameSprite() : sf::Sprite(){
    currentTextureID = -1;
}

GameSprite::GameSprite(TextureID textureID) : sf::Sprite(){
    setTexture(textureID, false);
}

void GameSprite::setTexture(const sf::Texture& texture, bool resetRect) {
    sf::Sprite::setTexture(texture, resetRect);
}

void GameSprite::setTexture(TextureID textureID, bool resetRect) {
    sf::Sprite::setTexture(*textureList.getTexture(textureID), resetRect);
    currentTextureID = textureID;
}

GameSprite::~GameSprite(){
    if (currentTextureID != -1) {
        textureList.notUsingTexture(currentTextureID);
    }
}
