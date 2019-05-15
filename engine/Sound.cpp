
// Console command to compile for debugging:
// g++ Sound.cpp -lsfml-graphics -lsfml-window -lsfml-system -I/usr/include/SFML/ -lsfml-audio -lsfml-network

#include <iostream>
#include "Sound.h"
#include "Entity.h"

//unsigned int currentID;

Sound::Sound() {}
void Sound::setSoundFilePath(char *fileName) {
    filePath = fileName;
}
int Sound::loadSoundFile(char *fileName) {
    if (!buffer->loadFromFile(filePath)) {
        loadedBuff = false;
        std::cout << "    loadSoundFile FAILED" << std::endl;
        return -1;
    }
    sound.setBuffer(*buffer);
    loadedBuff = true;
    return 1;
}
void Sound::setBuffer(sf::SoundBuffer *buffer) {
    sound.setBuffer(*buffer);
    loadedBuff = true;
}
void Sound::playSound() {
    sound.play();
}
void Sound::pauseSound() {
    sound.pause();   
}
void Sound::stopSound() {
    sound.stop();
}
void Sound::setSoundLoop(int setting) {
    if (setting == 1){
        sound.setLoop(true);
    } else {
        sound.setLoop(false);
    }
}
void Sound::setSoundVolume(unsigned int vol) {
    sound.setVolume(vol);
}
void Sound::setSoundPitch(double pitch) {
    sound.setPitch(pitch);
}
sf::SoundBuffer* Sound::getBuffer() {
    return buffer;
}
int Sound::loadedBuffer() {
    if (loadedBuff) return 1;
    else return 0;
}
int Sound::getSoundStatus() {
    return sound.getStatus();
}

int createSound(char *fileName, int giveBuffer) {
    Sound *sound = new Sound();
    sound->id = currentID;
    sound->setSoundFilePath(fileName);
    soundList.push_front(sound);
    if (giveBuffer > 0) {
        sound->loadSoundFile(fileName);
    } else {
        sound->loadedBuff = false;
    }
    return currentID++;
}
void setBuffer(int ID, int bufferID) {
    getSoundByID(ID)->setBuffer(getSoundByID(bufferID)->getBuffer());
}
void playSound(int ID) {
    getSoundByID(ID)->playSound();
}
void pauseSound(int ID) {
    getSoundByID(ID)->pauseSound();
}
void stopSound(int ID) {
    getSoundByID(ID)->stopSound();
}
void setSoundLoop(int ID, int setting) {
    getSoundByID(ID)->setSoundLoop(setting);
}
void setSoundVolume(int ID, unsigned int vol) {
    getSoundByID(ID)->setSoundVolume(vol);
}
void setSoundPitch(int ID, double pitch) {
    getSoundByID(ID)->setSoundPitch(pitch/100.0);
}
int getSoundStatus(int ID) {
    return getSoundByID(ID)->getSoundStatus();
}
Sound* getSoundByID(int ID) {
    for(std::list<Sound*>::iterator it=soundList.begin(); it != soundList.end(); ++it) {
        if((*it)->id == ID) {
            return *it;
        }
    }
    std::cout << "FAILED TO FIND REQUESTED ID" << std::endl;
    return NULL;
}


/*int main() {

    std::cout << "HI" << std::endl;
    
    sf::Clock clock;

    int anchor = createSound("../assets/parry.wav", 1);
    getSoundStatus(anchor);
    playSound(anchor);
    getSoundStatus(anchor);

    while ( clock.getElapsedTime() < sf::milliseconds(1000) ) {}
    pauseSound(anchor);
    getSoundStatus(anchor);
    int file2 = createSound("../assets/parry.wav", 0);
    setSoundPitch(file2, 75);
    setBuffer(file2, anchor);
    playSound(file2);

    while ( clock.getElapsedTime() < sf::milliseconds(2000) ) {}
    stopSound(anchor);
    getSoundStatus(anchor);
    int file3 = createSound("../assets/parry.wav", 0);
    setSoundPitch(file3, 50);
    setBuffer(file3, anchor);
    playSound(file3);
    
    while ( clock.getElapsedTime() < sf::milliseconds(3000) ) {}
    int file4 = createSound("../assets/parry.wav", 0);
    setSoundPitch(file4, 25);
    setBuffer(file4, anchor);
    playSound(file4);

    std::cout << "BYE" << std::endl;

    //FIXME: NEXT STEPS, CHANNELING AUDIO

    while ( clock.getElapsedTime() < sf::milliseconds(6000) ) {}
    
    return 0;
}*/
