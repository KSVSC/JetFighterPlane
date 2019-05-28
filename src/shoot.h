#include "main.h"

#ifndef SHOOT_H
#define SHOOT_H

class Shoot {
public:
    Shoot() {}
    Shoot(float x, float y, float z, color_t color);
    glm::vec3 position;
    float rotation;
    bool alive;
    void draw(glm::mat4 VP);
    void set_position(float x, float y, float z);
    double xspeed;
    double yspeed;
    double gravity;
    void tick();
    bounding_box_t getboundingbox();
private:
    VAO *object;
};

#endif // SHOOT_H