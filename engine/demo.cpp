#include <iostream>
#include <SFML/Graphics.hpp>

#include "main.h"

int main() {
    init(800, 600, 5, "ARPGMaker Demo Using C++");
    display();
    //Game Loop
    // Map* bacon = new Map();
    //std::cout << "Here\n";
    loadTexturesFromFile("../assets.txt");
    //std::cout << listSize();
    while(window.isOpen()){
        std::cout << mousePositionX() << "\n";
        systemEventHandler();
    }
    return 0;
}
