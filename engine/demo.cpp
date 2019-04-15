#include <iostream>
#include "main.cpp"

int main() {
    init(800, 600, "ARPGMaker Demo Using C++");
    display();
    //Game Loop
    Map* bacon = new Map();
    //std::cout << listSize();
    while(window.isOpen()){
        systemEventHandler();
    }
    return 0;
}
