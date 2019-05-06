
// Console command to compile for debugging:
// g++ Sound.cpp -lsfml-graphics -lsfml-window -lsfml-system -I/usr/include/SFML/ -lsfml-audio -lsfml-network

#include "Sound.h"


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
    sound.play();
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


char * createSound(char *fileName) {
    Sound *sound = new Sound();
    sound->loadSoundFile(fileName);
    soundList.push_front(sound);
    return fileName;
}
void setBuffer(char *filePath) {
    getSoundByFilePath(filePath)->setBuffer();
}
void playSound(char *filePath) {
    getSoundByFilePath(filePath)->playSound();
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
Sound* getSoundByFilePath(char *filePath) {
    for(std::list<Sound*>::iterator it=soundList.begin(); it != soundList.end(); ++it) {
        if((*it)->filePath == filePath) {
            return *it;
        }
    }
    return NULL;
}


/*int main() {
    //Audio *parry = new Audio();
    //parry->loadAudioFile("../assets/parry.wav");
    //parry->playAudio();
    //Audio *cough = new Audio();
    //cough->loadAudioFile("../assets/ahem.wav");
    //cough->playAudio();

    char *file = createSound("../assets/parry.wav");
    
    setBuffer(file);

    sf::Clock clock;

    setVolume(file,100);
    setLoop(file,1);
    playSound(file);

    while ( clock.getElapsedTime() < sf::milliseconds(500) ) {}
    setVolume(file,33);
    playSound(file);
    while ( clock.getElapsedTime() < sf::milliseconds(1000) ) {}
    setVolume(file,66);
    playSound(file);
    while ( clock.getElapsedTime() < sf::milliseconds(1500) ) {}
    setVolume(file,99);
    playSound(file);

    //FIXME: NEXT STEPS, CHANNELING AUDIO

    while(true) {}

    return 1;
}*/

