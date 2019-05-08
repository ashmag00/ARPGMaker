#include "collisions.h"

extern Map demoMap;

bool circleCollide(Entity *ent1, Entity *ent2) {
    // sqrt((x2-x1)^2 + (y2-y1)^2)
    float distance = sqrt(pow(ent2->x - ent1->x, 2) + pow(ent2->y - ent1->y,2));
    return distance < (ent1->radius + ent2->radius);
}

bool circleCollide(int ent1ID, int ent2ID) {
    Entity *tmp1 = demoMap.getEntityByID(ent1ID);
    Entity *tmp2 = demoMap.getEntityByID(ent2ID);

    // if (circleCollide(tmp1, tmp2)) {
    //     return 1;
    // }

    // return 0;
    return circleCollide(tmp1, tmp2);
}