#include "main.h"

#ifndef BULLET_H
#define BULLET_H

class Bullet {
public:
    Bullet() {}
    Bullet(float x, float y, float z, color_t color);
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
    bool up;
private:
    VAO *object;
};

#endif // BULLET