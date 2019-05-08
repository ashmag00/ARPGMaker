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
    demoMap = *(new Map(tileSize, 1, 1));
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
