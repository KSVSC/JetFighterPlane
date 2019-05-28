#include "main.h"

#ifndef BALL_H
#define BALL_H

class Ball {
public:
    Ball() {}
    Ball(float x, float y, float z, color_t color);
    glm::vec3 position;
    float rotation;
    void draw(glm::mat4 VP);
    void set_position(float x, float y, float z);
    bounding_box_t getboundingbox();
    double speed;
    bool alive;
private:
    VAO *object1;
    VAO *object2;
};

#endif // BALL_H