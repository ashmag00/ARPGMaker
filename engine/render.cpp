#ifndef RENDER_CPP
#define RENDER_CPP

#include <SFML/Audio.hpp>
#include <SFML/Graphics.hpp>
#include <queue>
#include <unordered_map>

#include "memory.h"

/**********************
 * Rendering system and functions
 *********************/
using namespace std;

sf::RenderWindow window;
queue<sf::Sprite*> buffer;
unordered_map<char *, sf::Texture> textureHash;

void display() {
    window.display();
}

void loadTexture(char *filePath) {
    sf::Texture tex;
    string fp(filePath);
    if (!tex.loadFromFile(fp)) return;
    textureHash[filePath] = tex;
}

void setBackground(char *filePath) {

}

void renderImage(char* filePath) {
    buffer.push(new sf::Sprite(textureHash[filePath]));
}

void renderScene() {
    // for(auto entity: g_tmap.entityList) {
    //     loadTexture(entity.texture);
    //     renderImage(entity.texture);
    // }
}

void draw() {
    while (!buffer.empty()) {
        window.draw(*buffer.front());
        delete buffer.front();
        buffer.pop();
    }
}

#endif
