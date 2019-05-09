#ifndef INPUTS_H
#define INPUTS_H
#include <SFML/Graphics.hpp>
#include <SFML/System.hpp>
#include <string.h>
extern sf::RenderWindow window;
int isKeyPressed(char *key);
int mousePositionX();
int mousePositionY();
bool mouseLeftClick();
#endif
