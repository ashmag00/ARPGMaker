#include <SFML/Audio.hpp>
#include <SFML/Graphics.hpp>
#include <queue>
#include <unordered_map>

#include "Map.cpp"

#ifndef RENDER_CPP
#define RENDER_CPP
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

void renderImage(char* filePath) {
    buffer.push(new sf::Sprite(textureHash[filePath]));
}

void draw() {
    while (!buffer.empty()) {
        window.draw(*buffer.front());
        delete buffer.front();
        buffer.pop();
    }
}

#endif
