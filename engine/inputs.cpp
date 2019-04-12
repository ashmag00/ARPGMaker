#include <string.h>

#include "render.cpp"

#ifndef INPUTS_CPP
#define INPUTS_CPP
using namespace std;

int isKeyPressed(char *key) {
    if (strcmp(key, "W") == 0 || strcmp(key, "w") == 0) {
        if (sf::Keyboard::isKeyPressed(sf::Keyboard::W))
            return 1;
    }

    if (strcmp(key, "S") == 0 || strcmp(key, "s") == 0) {
        if (sf::Keyboard::isKeyPressed(sf::Keyboard::S))
            return 1;
    }

    if (strcmp(key, "D") == 0 || strcmp(key, "d") == 0) {
        if (sf::Keyboard::isKeyPressed(sf::Keyboard::D))
            return 1;
    }

    if (strcmp(key, "A") == 0 || strcmp(key, "a") == 0) {
        if (sf::Keyboard::isKeyPressed(sf::Keyboard::A))
            return 1;
    }

    return 0;
}

#endif
