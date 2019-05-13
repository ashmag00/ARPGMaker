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
        //void setBuffer(sf::SoundBuffer buffer);
        void playSound();
        void pauseSound();
        void stopSound();
        void setLoop(int setting);
        void setVolume(unsigned int vol);
        int loadedBuffer();

        // Used for DEBUGGING
        int main();

        char *filePath;
        sf::SoundBuffer buffer;
        sf::Sound sound;
        bool loadedBuff;
};

char * createSound(char *fileName, int giveBuffer);
//void setBuffer(char *filePath);
void playSound(char *filePath);
void pauseSound(char *filePath);
void stopSound(char *filePath);
void setLoop(char *filePath, int setting);
void setVolume(char *filePath, unsigned int vol);
void accessBuffer(char *filePath);
Sound* getSoundByFilePath(char *filePath);
//SoundBuffer* getBufferByFilePath(char *filePath);


#else
class Sound;
std::list<Sound*> soundList;
#endif