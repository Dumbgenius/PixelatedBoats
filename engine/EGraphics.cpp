#include "EGraphics.h"

EGraphics::EGraphics(int wWidth, int wHeight) {
    wind = new sf::RenderWindow(sf::VideoMode(wWidth, wHeight), "SFML Engine Test", sf::Style::Titlebar | sf::Style::Close);
};

EGraphics::~EGraphics() {};

sf::RenderWindow *EGraphics::getWindow() {
    return wind;
}

int EGraphics::getWindowWidth() {
    return wind->getSize().x;
}

int EGraphics::getWindowHeight() {
    return wind->getSize().y;
}
