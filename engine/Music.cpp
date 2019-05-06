
// Console command to compile for debugging:
// g++ Music.cpp -lsfml-graphics -lsfml-window -lsfml-system -I/usr/include/SFML/ -lsfml-audio -lsfml-network

#include "Music.h"


Music::Music() {}
void Music::setFilePath(char *fileName) {
    filePath = fileName;
}
int Music::openMusicFile(char *fileName) {
    setFilePath(fileName);
    if (!music.openFromFile(filePath)) {
        return -1;
    }
    return 1;
}
void Music::playMusic() {
    music.play();   
}
void Music::pauseMusic() {
    music.pause();   
}
void Music::stopMusic() {
    music.stop();   
}


char * createMusic(char *fileName) {
    Music *music = new Music();
    music->openMusicFile(fileName);
    musicList.push_front(music);
    return fileName;
}
void playMusic(char *filePath) {
    getMusicByFilePath("../assets/parry.wav")->playMusic();
}
void pauseMusic(char *filePath) {
    getMusicByFilePath("../assets/parry.wav")->pauseMusic();
}
void stopMusic(char *filePath) {
    getMusicByFilePath("../assets/parry.wav")->stopMusic();
}
Music* getMusicByFilePath(char *filePath) {
    for(std::list<Music*>::iterator it=musicList.begin(); it != musicList.end(); ++it) {
        if((*it)->filePath == filePath) {
            return *it;
        }
    }
    return NULL;
}


/*int main2() {
    //Audio *parry = new Audio();
    //parry->loadAudioFile("../assets/parry.wav");
    //parry->playAudio();
    //Audio *cough = new Audio();
    //cough->loadAudioFile("../assets/ahem.wav");
    //cough->playAudio();


    char *file = createMusic("../assets/parry.wav");

    sf::Clock clock;

    playMusic(file);
    while ( clock.getElapsedTime() < sf::milliseconds(500) ) {}
    pauseMusic(file);
    while ( clock.getElapsedTime() < sf::milliseconds(650) ) {}
    stopMusic(file);
    playMusic(file);

    //FIXME: NEXT STEPS, CHANNELING AUDIO

    while(true) {}

    return 1;
}*/

