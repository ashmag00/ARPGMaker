#include <SFML/Audio.hpp>
#include <SFML/Graphics.hpp>

#ifndef RENDER_CPP
#define RENDER_CPP
/**********************
 * Rendering system and functions
 *********************/
sf::RenderWindow window;
using namespace std;

void display() {
    window.display();
}

void renderImage(char* filePath) {
    sf::Image image;
    string fp(filePath);
    // cout << fp << endl;
    image.loadFromFile(fp);
    //window.draw(image);
}
#endif
