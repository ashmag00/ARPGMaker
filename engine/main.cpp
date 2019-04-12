#ifndef MAIN_CPP
#define MAIN_CPP

//#include "Map.h"
#include "inputs.cpp"
#include "memory.h"

/******************
 * Initialize the engine
 *****************/
void init(int resX, int resY, char *title) {
    window.create(sf::VideoMode(resX, resY), title);
    currentID = 0;
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
