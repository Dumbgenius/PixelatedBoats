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
    std::string path;
    TextureItem(std::string texturePath) {
        texture = sf::Texture();
        isLoaded = false;
        path = texturePath;
    }
};

class TextureList
{
    public:
        TextureList();
        sf::Texture* getTexture(int textureID);
    private:
        std::vector<TextureItem> textures;
};

extern TextureList textureList; //this is supposed to be a constant texture list. hopefully.

#endif // TEXTURELIST_H
