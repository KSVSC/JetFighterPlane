#include "main.h"

#ifndef FUELTANK_H
#define FUELTANK_H

class Fueltank {
public:
    Fueltank() {}
    Fueltank(float x, float y,float z, color_t color);
    glm::vec3 position;
    float rotation;
    bool alive;
    void draw(glm::mat4 VP);
    void set_position(float x, float y,float z);
    void tick();    
    bounding_box_t getboundingbox();
    double speed;
private:
    VAO *object1;
    VAO *object2;
    VAO *object3;
};

#endif // FUELTANK_H