#include <SFML/Graphics.hpp>
#include <SFML/Audio.hpp>

// Console command to compile for debugging:
// g++ Sound.cpp -lsfml-graphics -lsfml-window -lsfml-system -I/usr/include/SFML/ -lsfml-audio -lsfml-network

#include "Sound.h"
#include "Map.h"


Sound::Sound() {}
void Sound::setFilePath(char *fileName) {
    filePath = fileName;
}
int Sound::loadSoundFile(char *fileName) {
    setFilePath(fileName);
    if (!buffer.loadFromFile(filePath)) {
        return -1;
    }
    return 1;
}
void Sound::setBuffer() {
    sound.setBuffer(buffer);
}
void Sound::playSound() {
    this->setBuffer();
    sound.play();   
}
void Sound::pauseSound() {
    //this->setBuffer();
    sound.pause();   
}

char * createSound(char *fileName) {
    Sound *sound = new Sound();
    sound->loadSoundFile(fileName);

    soundList.push_front(sound);

    return fileName;
}
void playSound(char *filePath) {
    getSoundByFilePath("../assets/parry.wav")->playSound();
}
void pauseSound(char *filePath) {
    getSoundByFilePath("../assets/parry.wav")->pauseSound();
}
Sound* getSoundByFilePath(char *filePath) {
    for(std::list<Sound*>::iterator it=soundList.begin(); it != soundList.end(); ++it) {
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

    char *file = createSound("../assets/parry.wav");
    
    sf::Clock clock;
    playSound("../assets/parry.wav");
    while ( clock.getElapsedTime() < sf::milliseconds(500) ) {}
    pauseSound("../assets/parry.wav");


    //FIXME: NEXT STEPS, CHANNELING AUDIO

    while(true) {}

    return 1;
}

