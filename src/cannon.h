
#include "main.h"

#ifndef CANNON_H
#define CANNON_H

class Cannon {
public:
    Cannon() {}
    Cannon(float x, float y, float z, color_t color);
    glm::vec3 position;
    float rotation;
    void draw(glm::mat4 VP);
    void set_position(float x, float y, float z);
    void tick();
    bounding_box_t getboundingbox();
    double speed;
    bool alive;
    bool killed;
    bool arrow;
private:
    VAO *object1;
    VAO *object2;
    VAO *object3;
    VAO *object4;
    VAO *object5;
    VAO *object6;
};

#endif // CANNON_H
