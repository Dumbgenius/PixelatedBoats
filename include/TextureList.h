#pragma once
#ifndef TEXTURELIST_H
#define TEXTURELIST_H

#include <SFML/Graphics.hpp>
#include <array>
#include <map>
#include <string>

enum TextureID {
    shipPlayer = 0,
    sea1
};

struct TextureItem {
    sf::Texture texture;
    bool isLoaded;
    int noUsing;
    std::string path;
    TextureItem(std::string texturePath) {
        texture = sf::Texture();
        isLoaded = false;
        path = texturePath;
        noUsing = 0;
    }
};

class TextureList
{
    public:
        TextureList();
        sf::Texture* getTexture(int textureID);
        void usingTexture(int textureID); //call in constructors
        void notUsingTexture(int textureID); //call in destructors
    private:
        void unloadTexture(int textureID);
        std::vector<TextureItem> textures;
};

extern TextureList textureList; //this is supposed to be a constant texture list. hopefully.

#endif // TEXTURELIST_H
