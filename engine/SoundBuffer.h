#ifndef SOUNDBUFFER_H
#define SOUNDBUFFER_H

// Console command to compile for debugging:
// g++ SoundBuffer.cpp -lsfml-graphics -lsfml-window -lsfml-system -I/usr/include/SFML/ -lsfml-audio -lsfml-network

#include <SFML/Graphics.hpp>
#include <SFML/Audio.hpp>
#include "Map.h"

class SoundBuffer {
    public:
        SoundBuffer();
        int loadSoundFile(char *fileName);
        void setFilePath(char *fileName);
        sf::SoundBuffer getBuffer();

        // Used for DEBUGGING
        //int main();

        char *filePath;
        sf::SoundBuffer buffer;
};

char * createSoundBuffer(char *fileName);
SoundBuffer* getBufferByFilePath(char *filePath);


#else
class SoundBuffer;
std::list<SoundBuffer*> soundBufferList;
#endif