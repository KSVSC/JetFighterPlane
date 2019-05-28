#include "main.h"

#ifndef FLY_BULLET_H
#define FLY_BULLET_H

class Fly_bullet {
public:
    Fly_bullet() {}
    Fly_bullet(float x, float y, float z, color_t color);
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

#endif // FLY_BULLET