#include <SFML/Audio.hpp>
#include <SFML/Graphics.hpp>
#include <string.h>
#include <fstream>
#include <iostream>

#include "memory.h"
#include "render.h"
#include "Map.h"

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
    if (!tex.loadFromFile(fp)) {
        std::cout << "Error: Couldn't load file " << filePath << std::endl;
        return;
    }
    textureHash[filePath] = tex;
}

void loadTexturesFromFile(char *filePath) {
    std::ifstream file(filePath);
    std::string line;
    while (std::getline(file, line)) {
        // sf::Texture tex;
        // if (!tex.loadFromFile(line)) return;
        // char *tmp = strdup(line.c_str());
        // textureHash[tmp] = tex;

        char *tmp = strdup(line.c_str());
        loadTexture(tmp);
    }
}

void setBackground(char *filePath) {
    for (int i = 0; i < demoMap.tileList.size(); i++) {
        demoMap.tileList[i]->texture = filePath;
    }
}

void renderBackground() {
    for (int i = 0; i < demoMap.tileList.size(); i++) {
        sf::Sprite *tile = new sf::Sprite(textureHash[demoMap.tileList[i]->texture]);
        int x = demoMap.tileList[i]->ID % demoMap.tileX * demoMap.tileSize;
        int y = demoMap.tileList[i]->ID / demoMap.tileX * demoMap.tileSize;
        tile->setPosition(x, y);
        buffer.push(tile);
    }
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

void renderEntities() {
    for(std::list<Entity*>::iterator it = demoMap.entityList.begin(); it != demoMap.entityList.end(); ++it) {
        sf::Sprite *entity = new sf::Sprite(textureHash[(*it)->texture]);
        entity->setPosition((*it)->x, (*it)->y);
        buffer.push(entity);
    }
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