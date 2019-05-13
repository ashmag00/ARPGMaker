
// Console command to compile for debugging:
// g++ Sound.cpp -lsfml-graphics -lsfml-window -lsfml-system -I/usr/include/SFML/ -lsfml-audio -lsfml-network

#include <iostream>
#include "Sound.h"
#include "SoundBuffer.h"

Sound::Sound() {}
void Sound::setFilePath(char *fileName) {
    filePath = fileName;
}
int Sound::loadSoundFile(char *fileName) {
    if (!buffer.loadFromFile(filePath)) {
        loadedBuff = false;
        return -1;
    }
    sound.setBuffer(buffer);
    loadedBuff = true;
    return 1;
}
/*void Sound::setBuffer(sf::SoundBuffer buffer) {
    sound.setBuffer(buffer);
}*/
void Sound::playSound() {
    std::cout << "            Sound::playSound(" << std::endl;
    sound.play();
    std::cout << "            Sound::playSound)" << std::endl;
}
void Sound::pauseSound() {
    sound.pause();   
}
void Sound::stopSound() {
    sound.stop();
}
void Sound::setLoop(int setting) {
    if (setting == 1){
        sound.setLoop(true);
    } else {
        sound.setLoop(false);
    }
}
void Sound::setVolume(unsigned int vol) {
    sound.setVolume(vol);
}
int Sound::loadedBuffer() {
    if (loadedBuff) return 1;
    else return 0;
}


char * createSound(char *fileName, int giveBuffer) {
    std::cout << "createSound(" << std::endl;
    Sound *sound = new Sound();
    sound->setFilePath(fileName);
    soundList.push_front(sound);
    if (giveBuffer > 0) {
        sound->loadSoundFile(fileName);
    } else {
        sound->loadedBuff = false;
    }
    std::cout << "createSound)" << std::endl;
    return fileName;
}
/*void setBuffer(char *filePath) {
    std::cout << "    setBuffer(" << std::endl;
    getSoundByFilePath(filePath)->setBuffer(getBufferByFilePath(filePath)->getBuffer());
    std::cout << "    setBuffer)" << std::endl;
}*/
void playSound(char *filePath) {
    std::cout << "playSound(" << std::endl;
    getSoundByFilePath(filePath)->playSound();
    std::cout << "playSound)" << std::endl;
}
void pauseSound(char *filePath) {
    getSoundByFilePath(filePath)->pauseSound();
}
void stopSound(char *filePath) {
    getSoundByFilePath(filePath)->stopSound();
}
void setLoop(char *filePath, int setting) {
    getSoundByFilePath(filePath)->setLoop(setting);
}
void setVolume(char *filePath, unsigned int vol) {
    getSoundByFilePath(filePath)->setVolume(vol);
}
void accessBuffer(char *filePath) {
    std::cout << "        accessBuffer(" << std::endl;
    getSoundByFilePath(filePath)->sound.getBuffer();
    std::cout << "        accessBuffer)" << std::endl;
}
Sound* getSoundByFilePath(char *filePath) {
    std::cout << "        getSoundByFilePath(" << std::endl;
    for(std::list<Sound*>::iterator it=soundList.begin(); it != soundList.end(); ++it) {
        if((*it)->filePath == filePath) {
            std::cout << "            " << (*it)->filePath << std::endl;
            std::cout << "        getSoundByFilePath)" << std::endl;
            return *it;
        }
    }
    std::cout << "FAIL" << std::endl;
    return NULL;
}


int main() {

    std::cout << "HI" << std::endl;

    ////char *buf = createSoundBuffer("../assets/parry.wav");
    ////sf::SoundBuffer b = getBufferByFilePath(buf)->getBuffer();
    
    char *anchor = createSound("../assets/parry.wav", 1);


    sf::Clock clock;

    playSound(anchor);

    while ( clock.getElapsedTime() < sf::milliseconds(1000) ) {}
    //playSound(file2);

    char *file2 = createSound("../assets/parry.wav", 0);

    playSound(anchor);

    std::cout << "BYE" << std::endl;

    //FIXME: NEXT STEPS, CHANNELING AUDIO

    while(true) {}

    return 1;
}

