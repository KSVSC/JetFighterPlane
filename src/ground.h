#include "main.h"

#ifndef GROUND_H
#define GROUND_H

class Ground {
public:
    Ground() {}
    Ground(float x, float y, float z, color_t color);
    glm::vec3 position;
    float rotation;
    void draw(glm::mat4 VP);
    void set_position(float x, float y, float z);
    void tick();
    bounding_box_t getboundingbox();
    double speed;
private:
    VAO *object;
};

#endif // GROUND_H
