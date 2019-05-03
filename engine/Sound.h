#ifndef SOUND_H
#define SOUND_H

// Console command to compile for debugging:
// g++ Sound.cpp -lsfml-graphics -lsfml-window -lsfml-system -I/usr/include/SFML/ -lsfml-audio -lsfml-network

#include <SFML/Graphics.hpp>
#include <SFML/Audio.hpp>
#include "Map.h"

class Sound {
    public:
        Sound();
        void setFilePath(char *fileName);
        int loadSoundFile(char *fileName);
        void setBuffer();
        void playSound();
        void pauseSound();
        void stopSound();

        // Used for DEBUGGING
        int main3();

        char *filePath;
        sf::SoundBuffer buffer;
        sf::Sound sound;
};

char * createSound(char *fileName);
void setBuffer(char *filePath);
void playSound(char *filePath);
void pauseSound(char *filePath);
void stopSound(char *filePath);
Sound* getSoundByFilePath(char *filePath);

#else
class Sound;
std::list<Sound*> soundList;
#endif