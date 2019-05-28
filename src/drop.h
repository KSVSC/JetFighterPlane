#include "main.h"

#ifndef DROP_H
#define DROP_H

class Drop {
public:
    Drop() {}
    Drop(float x, float y, float z, color_t color);
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

#endif // DROP_H