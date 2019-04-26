#include <SFML/Graphics.hpp>
#include <SFML/Audio.hpp>

// g++ Audio.cpp -lsfml-graphics -lsfml-window -lsfml-system -I/usr/include/SFML/ -lsfml-audio -lsfml-network

//#include "Audio.h"

int main() {
    sf::SoundBuffer buffer;
    if (!buffer.loadFromFile("../assets/ahem.wav")) {
        return -1;
    }
    
    sf::Sound sound;
    sound.setBuffer(buffer);
    sound.play();


    while(true) {}

    return 1;
}