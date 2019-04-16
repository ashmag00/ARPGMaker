#include <SFML/Graphics.hpp>
#include <SFML/Audio.hpp>

#include "Map.h"
#include "inputs.h"
#include "memory.h"
#include "render.h"

#include "main.h"

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
        if(event.type == sf::Event::Closed || ((event.type == sf::Event::KeyPressed)
           && event.key.code == sf::Keyboard::Escape))
            close();
    }
}
