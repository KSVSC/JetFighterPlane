
#include "main.h"

#ifndef SMOKERING_H
#define SMOKERING_H

class Smokering {
public:
    Smokering() {}
    Smokering(float x, float y, float z, color_t color);
    glm::vec3 position;
    float rotation;
    void draw(glm::mat4 VP);
    void set_position(float x, float y, float z);
    bounding_box_t getboundingbox();
    double speed;
    bool killed;
private:
    VAO *object1;
};

#endif // SMOKERING_H
