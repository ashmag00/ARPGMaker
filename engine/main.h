#ifndef MAIN_H
#define MAIN_H

#include "render.h"
#include "inputs.h"
#include "Entity.h"
#include "Map.h"
#include "memory.h"
#include "collisions.h"

void init(int resX, int resY, int tileSize, char *title);
void close();
bool isOpen();
void systemEventHandler();

#endif
