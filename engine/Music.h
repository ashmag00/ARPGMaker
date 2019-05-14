#ifndef MUSIC_H
#define MUSIC_H

// Console command to compile for debugging:
// g++ Music.cpp -lsfml-graphics -lsfml-window -lsfml-system -I/usr/include/SFML/ -lsfml-audio -lsfml-network

#include <SFML/Graphics.hpp>
#include <SFML/Audio.hpp>
#include "Map.h"
#include "memory.h"

extern unsigned int currentID;

class Music {
    public:
        Music();
        void setFilePath(char *fileName);
        int openMusicFile(char *fileName);
        void playMusic();
        void pauseMusic();
        void stopMusic();
        void setLoop(int setting);
        void setVolume(unsigned int vol);

        // Used for DEBUGGING
        int main();

        int id;
        char *filePath;
        sf::Music music;
};

int createMusic(int ID);
void playMusic(int ID);
void pauseMusic(int ID);
void stopMusic(int ID);
void setLoop(int ID, int setting);
void setVolume(int ID, unsigned int vol);
Music* getMusicByID(int ID);

#else
class Music;
std::list<Music*> musicList;
#endif