#ifndef SOUND_H
#define SOUND_H


class Sound {
    public:
        Sound();
        //void setFilePath(char *filePath);
        void setFilePath(char *fileName);
        int loadSoundFile(char *fileName);
        void setBuffer();
        void playSound();

        // Used for DEBUGGING
        int main();

        char *filePath;
        sf::SoundBuffer buffer;
        sf::Sound sound;
};

char * createSound(char *fileName);
void playSound(char *filePath);
Sound* getSoundByFilePath(char *filePath);

#else

class Sound;
std::list<Sound*> soundList;

#endif