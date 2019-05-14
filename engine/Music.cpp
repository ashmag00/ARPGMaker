
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
    std::cout << "    Music::openMusicFile(" << std::endl;
    if (!music.openFromFile(fileName)) {
        std::cout << "    Music::openMusicFile FAILED" << std::endl;
        return -1;
    }
    std::cout << "    Music::openMusicFile)" << std::endl;
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


int createMusic(char *fileName) {
    std::cout << "createSound(" << std::endl;
    Music *music = new Music();
    music->id = currentID;
    music->openMusicFile(fileName);
    music->setMusicFilePath(fileName);
    musicList.push_front(music);
    std::cout << "createSound)" << std::endl;
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
Music* getMusicByID(int ID) {
    for(std::list<Music*>::iterator it=musicList.begin(); it != musicList.end(); ++it) {
        if((*it)->id == ID) {
            return *it;
        }
    }
    return NULL;
}


/*int main() {

    std::cout << "HI" << std::endl;

    int anchor = createMusic("../assets/parry.wav");
    
    playMusic(anchor);
    setMusicLoop(anchor, 1);
    setMusicVolume(anchor, 25);

    //sf::Clock clock;
    
    //while ( clock.getElapsedTime() < sf::milliseconds(500) ) {}
    //pauseMusic(anchor);
    //while ( clock.getElapsedTime() < sf::milliseconds(650) ) {}
    //stopMusic(anchor);
    //playMusic(anchor);

    std::cout << "GOODBYE" << std::endl;

    //FIXME: NEXT STEPS, CHANNELING AUDIO

    while(true) {}

    return 1;
}*/

