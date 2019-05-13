
// Console command to compile for debugging:
// g++ SoundBuffer.cpp -lsfml-graphics -lsfml-window -lsfml-system -I/usr/include/SFML/ -lsfml-audio -lsfml-network

#include "SoundBuffer.h"
#include <iostream>

SoundBuffer::SoundBuffer() {}
void SoundBuffer::setFilePath(char *fileName) {
    filePath = fileName;
}
int SoundBuffer::loadSoundFile(char *fileName) {
    std::cout << "    SoundBuffer::loadSoundFile(" << std::endl;
    setFilePath(fileName);
    if (!buffer.loadFromFile(filePath)) {
        std::cout << "FAILED LOAD" << std::endl;
        return -1;
    }
    std::cout << "    SoundBuffer::loadSoundFile)" << std::endl;
    return 1;
}
sf::SoundBuffer SoundBuffer::getBuffer() {
    std::cout << "                SoundBuffer::getBuffer(" << std::endl;
    std::cout << "                SoundBuffer::getBuffer)" << std::endl;
    return this->buffer;
}

char * createSoundBuffer(char* fileName) {
    std::cout << "createBuffer(" << std::endl;
    SoundBuffer *soundBuffer = new SoundBuffer();
    soundBuffer->loadSoundFile(fileName);
    soundBufferList.push_front(soundBuffer);
    std::cout << "createBuffer)" << std::endl;
    return fileName;
}
SoundBuffer* getBufferByFilePath(char *filePath) {
    std::cout << "        getBufferByFilePath(" << std::endl;
    for(std::list<SoundBuffer*>::iterator it=soundBufferList.begin(); it != soundBufferList.end(); ++it) {
        if((*it)->filePath == filePath) {
            std::cout << "            " << (*it)->filePath << std::endl;
            std::cout << "        getBufferByFilePath)" << std::endl;
            return *it;
        }
    }
    std::cout << "FAIL" << std::endl;
    return NULL;
}

/*int main() {


    char *buffer = createSoundBuffer("../assets/parry.wav");
    char *file = createSound("../assets/parry.wav");

}*/
