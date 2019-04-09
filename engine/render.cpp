#include <SFML/Audio.hpp>
#include <SFML/Graphics.hpp>
#include <queue>
#include <unordered_map>

#ifndef RENDER_CPP
#define RENDER_CPP
/**********************
 * Rendering system and functions
 *********************/
using namespace std;

sf::RenderWindow window;
queue<sf::Sprite*> buffer;
unordered_map<char *, sf::Texture> textureMap;
// sf::Sprite background;

void display() {
    window.display();
}

void loadTexture(char *filePath) {
    sf::Texture tex;
    string fp(filePath);
    if (!tex.loadFromFile(fp)) return;
    // textureMap.insert(make_pair<char*, sf::Texture>(filePath, tex));
    textureMap[filePath] = tex;
}

void renderImage(char* filePath) {
    // background.setTexture(tex);
    // background.setPosition(400.f, 300.f);
    buffer.push(new sf::Sprite(textureMap[filePath]));
    // window.draw(background);
}

void draw() {
    while (!buffer.empty()) {
        window.draw(*buffer.front());
        delete buffer.front();
        buffer.pop();
    }

    // window.draw(background);
}

#endif
