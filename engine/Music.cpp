
// Console command to compile for debugging:
// g++ Music.cpp Entity.cpp -lsfml-graphics -lsfml-window -lsfml-system -I/usr/include/SFML/ -lsfml-audio -lsfml-network

#include <iostream>
#include "Music.h"
#include "Entity.h"

//unsigned int currentID;

Music::Music() {}
void Music::setMusicFilePath(char *fileName) {
    filePath = fileName;
}
int Music::openMusicFile(char *fileName) {
    if (!music.openFromFile(fileName)) {
        std::cout << "    Music::openMusicFile FAILED" << std::endl;
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
void Music::setMusicLoop(int setting) {
    if (setting == 1) {
        music.setLoop(true);
    } else {
        music.setLoop(false);
    }
}
void Music::setMusicVolume(unsigned int vol) {
    music.setVolume(vol);
}
void Music::setMusicPitch(double pitch) {
    music.setPitch(pitch);
}
int Music::getMusicStatus(int ID) {
    return music.getStatus();
}

int createMusic(char *fileName) {
    Music *music = new Music();
    music->id = currentID;
    music->openMusicFile(fileName);
    music->setMusicFilePath(fileName);
    musicList.push_front(music);
    return currentID++;
}
void playMusic(int ID) {
    getMusicByID(ID)->playMusic();
}
void pauseMusic(int ID) {
    getMusicByID(ID)->pauseMusic();
}
void stopMusic(int ID) {
    getMusicByID(ID)->stopMusic();
}
void setMusicLoop(int ID, int setting) {
    getMusicByID(ID)->setMusicLoop(setting);
}
void setMusicVolume(int ID, unsigned int vol) {
    getMusicByID(ID)->setMusicVolume(vol);
}
void setMusicPitch(int ID, int pitch) {
    getMusicByID(ID)->setMusicPitch(pitch/100.0);
}
int getMusicStatus(int ID) {
    return getMusicByID(ID)->getMusicStatus(ID);
}
Music* getMusicByID(int ID) {
    for(std::list<Music*>::iterator it=musicList.begin(); it != musicList.end(); ++it) {
        if((*it)->id == ID) {
            return *it;
        }
    }
    std::cout << "FAILED TO FIND REQUESTED ID" << std::endl;
    return NULL;
}


/*int main() {

    std::cout << "HI" << std::endl;
    int anchor = createMusic("../assets/parry.wav");
    
    playMusic(anchor);
    setMusicVolume(anchor, 100);

    sf::Clock clock;
    
    while ( clock.getElapsedTime() < sf::milliseconds(1500) ) {}
    
    setMusicPitch(anchor, 50);
    playMusic(anchor);

    std::cout << "GOODBYE" << std::endl;

    //FIXME: NEXT STEPS, CHANNELING AUDIO

    while(true) {}

    return 1;
}*/

