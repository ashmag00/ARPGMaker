#ifndef RENDER_H
#define RENDER_H
#include <queue>
#include <unordered_map>
extern sf::RenderWindow window;
extern std::queue<sf::Sprite*> buffer;
extern std::unordered_map<char *, sf::Texture> textureHash;
void display();
void loadTexture(char *filePath);
void setBackground(char *filePath);
void renderImage(char *filePath);
void renderScene();
void draw();
#endif
