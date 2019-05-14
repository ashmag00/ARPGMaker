#include "collisions.h"

extern Map demoMap;
extern std::unordered_map<char *, sf::Texture> textureHash;

bool circleCollide(Entity *ent1, Entity *ent2) {
    // sqrt((x2-x1)^2 + (y2-y1)^2)
    sf::Texture tex1 = textureHash[ent1->texture];
    sf::Texture tex2 = textureHash[ent2->texture];
    sf::Vector2u vec1 = tex1.getSize();
    sf::Vector2u vec2 = tex2.getSize();
    float distance = sqrt(pow(ent2->x + (vec2.x / 2) - (
        ent1->x + (vec1.y / 2)),2) + pow(ent2->y + (vec2.y / 2) - (ent1->y + (vec1.y / 2)),2));
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