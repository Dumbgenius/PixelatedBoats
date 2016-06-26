#pragma once
#include <SFML/Graphics.hpp>

class EGraphics {
public:
    EGraphics(int wWidth, int wHeight);
    ~EGraphics();

    sf::RenderWindow *getWindow();
    int getWindowHeight();
    int getWindowWidth();
private:
    sf::RenderWindow *wind;
};
