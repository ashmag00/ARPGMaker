
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
char * createMusic(char *fileName) {
    Music *music = new Music();
    music->openMusicFile(fileName);
    musicList.push_front(music);
    return fileName;
}
void playMusic(char *filePath) {
    getMusicByFilePath("../assets/parry.wav")->playMusic();
}
Music* getMusicByFilePath(char *filePath) {
    for(std::list<Music*>::iterator it=musicList.begin(); it != musicList.end(); ++it) {
        if((*it)->filePath == filePath) {
            return *it;
        }
    }
    return NULL;
}


/*int main() {
    Audio *parry = new Audio();
    parry->loadAudioFile("../assets/parry.wav");
    parry->playAudio();
    Audio *cough = new Audio();
    cough->loadAudioFile("../assets/ahem.wav");
    cough->playAudio();


    char *file = createMusic("../assets/parry.wav");
    playMusic("../assets/parry.wav");

    //FIXME: NEXT STEPS, CHANNELING AUDIO

    while(true) {}

    return 1;
}*/

