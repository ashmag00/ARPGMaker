#ifndef MAIN_H
#define MAIN_H

#include "render.h"
#include "inputs.h"
#include "Entity.h"
#include "Map.h"

void init(int resX, int resY, char *title);
void close();
bool isOpen();
void systemEventHandler();

#endif
