#include "main.cpp"

int main() {
    init(800, 600, "ARPGMaker Demo Using C++");
    display();
    //Game Loop
    while(window.isOpen()){
        systemEventHandler();
    }
    return 0;
}
