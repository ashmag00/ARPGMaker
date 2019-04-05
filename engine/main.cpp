#include <SFML/Audio.hpp>
#include <SFML/Graphics.hpp>
//#include "Map.h"
sf::RenderWindow window;

/******************
 * Initialize the engine
 *****************/
void init(int resX, int resY, std::string title) {
    window.create(sf::VideoMode(resX, resY), title);
}


void display() {
    window.display();
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

