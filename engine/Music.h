#ifndef MUSIC_H
#define MUSIC_H

// Console command to compile for debugging:
// g++ Music.cpp -lsfml-graphics -lsfml-window -lsfml-system -I/usr/include/SFML/ -lsfml-audio -lsfml-network

#include <SFML/Graphics.hpp>
#include <SFML/Audio.hpp>
#include "Map.h"

class Music {
    public:
        Music();
        void setFilePath(char *fileName);
        int openMusicFile(char *fileName);
        void playMusic();
        void pauseMusic();
        void stopMusic();

        // Used for DEBUGGING
        int main();

        char *filePath;
        sf::Music music;
};

char * createMusic(char *fileName);
void playMusic(char *filePath);
void pauseMusic(char *filePath);
void stopMusic(char *filePath);
Music* getMusicByFilePath(char *filePath);

#else
class Music;
std::list<Music*> musicList;
#endif