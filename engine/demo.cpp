#include <iostream>
#include <SFML/Graphics.hpp>

#include "main.h"

int main() {
    init(800, 600, 32, "ARPGMaker Demo Using C++");
    display();
    //Game Loop
    // Map* bacon = new Map();
    Entity* ent = new Entity(200, 200, true, 5);
    //std::cout << "Here\n";
    loadTexturesFromFile("../assets.txt");
    //std::cout << listSize();
    while(window.isOpen()){
        systemEventHandler();
    }
    return 0;
}
