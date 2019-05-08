#include <SFML/Graphics.hpp>
#include <SFML/Audio.hpp>

#include "main.h"

extern Map demoMap;

/******************
 * Initialize the engine
 *****************/
void init(int resX, int resY, int tileSize, char *title) {
    window.create(sf::VideoMode(resX, resY), title);
    currentID = 0;
    int tileX = ceil((float) resX / tileSize);
    int tileY = ceil((float) resY / tileSize);
    demoMap = *(new Map(tileSize, tileX, tileY));
}

/******************
 * Close the engine
 *****************/
void close() {
    window.close();
}

bool isOpen() {
    return window.isOpen();
}

/*****************
 * Handle system events
 ****************/
void systemEventHandler() {
    sf::Event event;
    while (window.pollEvent(event)) {
        //Process Event
        if(event.type == sf::Event::Closed || ((event.type == sf::Event::KeyPressed)
           && event.key.code == sf::Keyboard::Escape))
            close();
    }
}
