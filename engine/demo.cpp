#include <iostream>
#include <SFML/Graphics.hpp>

#include "main.h"

int main() {
    init(800, 600, "ARPGMaker Demo Using C++");
    display();
    //Game Loop
    Map* bacon = new Map();
    loadTexturesFromFile("../assets.txt");
    //std::cout << listSize();
    while(window.isOpen()){
        systemEventHandler();
    }
    return 0;
}
