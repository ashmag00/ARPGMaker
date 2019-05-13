
// Console command to compile for debugging:
// g++ Sound.cpp -lsfml-graphics -lsfml-window -lsfml-system -I/usr/include/SFML/ -lsfml-audio -lsfml-network

#include <iostream>
#include "Sound.h"

unsigned int currentID;

Sound::Sound() {}
void Sound::setFilePath(char *fileName) {
    filePath = fileName;
}
int Sound::loadSoundFile(char *fileName) {
    std::cout << "    Sound::loadSoundFile(" << std::endl;
    if (!buffer->loadFromFile(filePath)) {
        loadedBuff = false;
        std::cout << "    loadSoundFile FAILED" << std::endl;
        return -1;
    }
    sound.setBuffer(*buffer);
    loadedBuff = true;
    std::cout << "    Sound::loadSoundFile)" << std::endl;
    return 1;
}
void Sound::setBuffer(sf::SoundBuffer *buffer) {
    sound.setBuffer(*buffer);
    loadedBuff = true;
}
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
int Sound::getID() {
    return id;
}
sf::SoundBuffer* Sound::getBuffer() {
    return buffer;
}
int Sound::loadedBuffer() {
    if (loadedBuff) return 1;
    else return 0;
}


int createSound(char *fileName, int giveBuffer) {
    std::cout << "createSound(" << std::endl;
    Sound *sound = new Sound();
    sound->id = currentID;
    sound->setFilePath(fileName);
    soundList.push_front(sound);
    if (giveBuffer > 0) {
        sound->loadSoundFile(fileName);
    } else {
        sound->loadedBuff = false;
    }
    std::cout << "createSound)" << std::endl;
    return currentID++;
}
void setBuffer(int ID, int bufferID) {
    std::cout << "    setBuffer(" << std::endl;
    getSoundByID(ID)->setBuffer(getSoundByID(bufferID)->getBuffer());
    std::cout << "    setBuffer)" << std::endl;
}
void playSound(int ID) {
    std::cout << "playSound(" << std::endl;
    getSoundByID(ID)->playSound();
    std::cout << "playSound)" << std::endl;
}
void pauseSound(int ID) {
    getSoundByID(ID)->pauseSound();
}
void stopSound(int ID) {
    getSoundByID(ID)->stopSound();
}
void setLoop(int ID, int setting) {
    getSoundByID(ID)->setLoop(setting);
}
void setVolume(int ID, unsigned int vol) {
    getSoundByID(ID)->setVolume(vol);
}
void accessBuffer(int ID) {
    std::cout << "        accessBuffer(" << std::endl;
    getSoundByID(ID)->sound.getBuffer();
    std::cout << "        accessBuffer)" << std::endl;
}
Sound* getSoundByID(int ID) {
    std::cout << "        getSoundByID(" << std::endl;
    for(std::list<Sound*>::iterator it=soundList.begin(); it != soundList.end(); ++it) {
        if((*it)->id == ID) {
            std::cout << "            " << (*it)->filePath << std::endl;
            std::cout << "        getSoundByID)" << std::endl;
            return *it;
        }
    }
    std::cout << "FAIL" << std::endl;
    return NULL;
}


int main() {

    std::cout << "HI" << std::endl;
    
    sf::Clock clock;

    int anchor = createSound("../assets/parry.wav", 1);
    playSound(anchor);
    std::cout << "HI" << std::endl;

    while ( clock.getElapsedTime() < sf::milliseconds(10) ) {}
    int file2 = createSound("../assets/parry.wav", 0);
    setBuffer(file2, anchor);
    playSound(file2);

    while ( clock.getElapsedTime() < sf::milliseconds(20) ) {}
    int file3 = createSound("../assets/parry.wav", 0);
    setBuffer(file3, anchor);
    playSound(file3);
    
    while ( clock.getElapsedTime() < sf::milliseconds(30) ) {}
    int file4 = createSound("../assets/parry.wav", 0);
    setBuffer(file4, anchor);
    playSound(file4);

    std::cout << "BYE" << std::endl;

    //FIXME: NEXT STEPS, CHANNELING AUDIO


    while ( clock.getElapsedTime() < sf::milliseconds(4000) ) {}
    
    return 0;
}

