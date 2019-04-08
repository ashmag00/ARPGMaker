//#include "Map.h"
#include "inputs.cpp"
#include "render.cpp"

#ifndef MAIN_CPP
#define MAIN_CPP

/******************
 * Initialize the engine
 *****************/
void init(int resX, int resY, char *title) {
    window.create(sf::VideoMode(resX, resY), title);
}

/******************
 * Close the engine
 *****************/
void close() {
    window.close();
}

/*****************
 * Handle system events
 ****************/
void systemEventHandler() {
    sf::Event event;
    while (window.pollEvent(event)) {
        //Process Event
        if(event.type == sf::Event::Closed)
            close();
    }
}
#endif
