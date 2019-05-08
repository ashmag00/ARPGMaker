#include "collisions.h"

bool circleCollide(Entity* ent1, Entity *ent2) {
    // sqrt((x2-x1)^2 + (y2-y1)^2)
    float distance = sqrt(pow(ent2->x - ent1->x, 2) + pow(ent2->y - ent1->y,2));
    return distance < (ent1->radius + ent2->radius);
}
