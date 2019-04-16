#include <SFML/Audio.hpp>
#include <SFML/Graphics.hpp>
#include <string>

#include "memory.h"
#include "render.h"
extern Map demoMap;

/**********************
 * Rendering system and functions
 *********************/
sf::RenderWindow window;
std::queue<sf::Sprite*> buffer;
std::unordered_map<char *, sf::Texture> textureHash;

void display() {
    window.display();
}

void loadTexture(char *filePath) {
    sf::Texture tex;
    std::string fp(filePath);
    if (!tex.loadFromFile(fp)) return;
    textureHash[filePath] = tex;
}

void setBackground(char *filePath) {

}

void renderImage(char *filePath) {
    buffer.push(new sf::Sprite(textureHash[filePath]));
}

void renderEntity(unsigned int id) {
    Entity *tmp = demoMap.getEntityByID(id);
    sf::Sprite *entity = new sf::Sprite(textureHash[tmp->texture]);
    entity->setPosition(tmp->x, tmp->y);
    buffer.push(entity);
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

void clear() {
    window.clear(sf::Color::Black);
}