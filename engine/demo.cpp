#include <iostream>
#include <SFML/Graphics.hpp>

#include "main.h"

int main() {
    init(800, 600, 32, "ARPGMaker Demo Using C++");
    display();
    //Game Loop
    // Map* bacon = new Map();
    Entity* ent = new Entity(0, 0, true, 5);
    Entity* collider = new Entity(5, 5, true, 5);
    std::cout << circleCollide(ent, collider) << "\n";
    //std::cout << "Here\n";
    loadTexturesFromFile("../assets.txt");
    //std::cout << listSize();
    while(window.isOpen()){
        systemEventHandler();
    }
    return 0;
}
