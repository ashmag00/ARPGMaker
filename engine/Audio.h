#ifndef AUDIO_H
#define AUDIO_H


class Audio {
    public:
        Audio();
        //void setFilePath(char *filePath);
        void setFilePath(char *fileName);
        int loadAudioFile(char *fileName);
        void setBuffer();
        void playAudio();
        int main();

        char *filePath;
        sf::SoundBuffer buffer;
        sf::Sound sound;
};

char * createAudio(char *fileName);
void playAudio(char *filePath);
Audio* getAudioByFilePath(char *filePath);

#else

class Audio;
std::list<Audio*> audioList;

#endif