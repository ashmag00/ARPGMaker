#include <SFML/Audio.hpp>
#include <SFML/Graphics.hpp>
#include <queue>

#ifndef RENDER_CPP
#define RENDER_CPP
/**********************
 * Rendering system and functions
 *********************/
sf::RenderWindow window;
using namespace std;

queue<sf::Sprite> buffer;
sf::Sprite background;

void display() {
    window.display();
}

void renderImage(char* filePath) {
    sf::Texture tex;
    string fp(filePath);
    // cout << fp << endl;
    if (!tex.loadFromFile(fp)) return;
    background.setTexture(tex);
    // background.setPosition(400.f, 300.f);
    buffer.push(background);
    window.draw(background);
}

void draw() {
    //while (!buffer.empty()) {
        //window.draw(buffer.front());
      //  buffer.pop();
    //}
    window.draw(background);
}

#endif
