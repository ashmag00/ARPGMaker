#ifndef MUSIC_H
#define MUSIC_H

class Music {
    public:
        Music();
        void setFilePath(char *fileName);
        int openMusicFile(char *fileName);
        void playMusic();

        // Used for DEBUGGING
        int main();

        char *filePath;
        sf::Music music;
};

char * createMusic(char *fileName);
void playMusic(char *filePath);
Music* getMusicByFilePath(char *filePath);

#else
class Music;
std::list<Music*> musicList;
#endif