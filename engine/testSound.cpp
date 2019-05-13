
// g++ testSound.cpp Sound.cpp SoundBuffer.cpp -lsfml-graphics -lsfml-window -lsfml-system -I/usr/include/SFML/ -lsfml-audio -lsfml-network
// g++ testSound.cpp -lsfml-graphics -lsfml-window -lsfml-system -I/usr/include/SFML/ -lsfml-audio -lsfml-network

#include <SFML/Graphics.hpp>
#include <SFML/Audio.hpp>
//#include "Map.h"
#include "Sound.h"
#include "SoundBuffer.h"

int main () {
    
    char *buf = createSoundBuffer("../assets/parry.wav");
    char *file = createSound("../assets/parry.wav");

    playSound(file);

}
