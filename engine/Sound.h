#ifndef SOUND_H
#define SOUND_H

// Console command to compile for debugging:
// g++ Sound.cpp -lsfml-graphics -lsfml-window -lsfml-system -I/usr/include/SFML/ -lsfml-audio -lsfml-network

#include <SFML/Graphics.hpp>
#include <SFML/Audio.hpp>
#include "Map.h"
#include "memory.h"

extern unsigned int currentID;

class Sound {
    public:
        Sound();
        void setFilePath(char *fileName);
        int loadSoundFile(char *fileName);
        void setBuffer(sf::SoundBuffer *buffer);
        void playSound();
        void pauseSound();
        void stopSound();
        void setLoop(int setting);
        void setVolume(unsigned int vol);
        sf::SoundBuffer* getBuffer();
        int loadedBuffer();

        // Used for DEBUGGING
        //int main();

        int id;
        char *filePath;
        sf::SoundBuffer *buffer = new sf::SoundBuffer;
        sf::Sound sound;
        bool loadedBuff;
};

int createSound(char *fileName, int giveBuffer);
void setBuffer(int ID, int bufferID);
void playSound(int ID);
void pauseSound(int ID);
void stopSound(int ID);
void setLoop(int ID, int setting);
void setVolume(int ID, unsigned int vol);
void accessBuffer(int ID);
Sound* getSoundByID(int ID);

#else
class Sound;
std::list<Sound*> soundList;
#endif