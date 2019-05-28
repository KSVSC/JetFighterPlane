
#include "main.h"

#ifndef PARACHUTES_H
#define PARACHUTES_H

class Parachutes {
public:
    Parachutes() {}
    Parachutes(float x, float y, float z, color_t color);
    glm::vec3 position;
    float rotation;
    void draw(glm::mat4 VP);
    void set_position(float x, float y, float z);
    void tick();
    bounding_box_t getboundingbox();
    double speed;
    double speed1;
    bool alive;
    bool killed;
private:
    VAO *object1;
    VAO *object2;
    VAO *object3;
};

#endif // PARACHUTES_H
