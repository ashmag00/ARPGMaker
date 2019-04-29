#include <SFML/Graphics.hpp>
#include <SFML/Audio.hpp>

// g++ Audio.cpp -lsfml-graphics -lsfml-window -lsfml-system -I/usr/include/SFML/ -lsfml-audio -lsfml-network

#include "Audio.h"
#include "Map.h"


Audio::Audio() {}
void Audio::setFilePath(char *fileName) {
    filePath = fileName;
}
int Audio::loadAudioFile(char *fileName) {
    setFilePath(fileName);
    if (!buffer.loadFromFile(filePath)) {
        return -1;
    }
    return 1;
}
void Audio::setBuffer() {
    sound.setBuffer(buffer);
}
void Audio::playAudio() {
    this->setBuffer();
    sound.play();   
}

char * createAudio(char *fileName) {
    Audio *audio = new Audio();
    audio->loadAudioFile(fileName);

    audioList.push_front(audio);

    return fileName;
}
void playAudio(char *filePath) {
    getAudioByFilePath("../assets/parry.wav")->playAudio();
}
Audio* getAudioByFilePath(char *filePath) {
    for(std::list<Audio*>::iterator it=audioList.begin(); it != audioList.end(); ++it) {
        if((*it)->filePath == filePath) {
            return *it;
        }
    }
    return NULL;
}


int main() {
    /*Audio *parry = new Audio();
    parry->loadAudioFile("../assets/parry.wav");
    parry->playAudio();
    Audio *cough = new Audio();
    cough->loadAudioFile("../assets/ahem.wav");
    cough->playAudio();*/


    char *file = createAudio("../assets/parry.wav");
    playAudio("../assets/parry.wav");

    //FIXME: NEXT STEPS, CHANNELING AUDIO

    while(true) {}

    return 1;
}

