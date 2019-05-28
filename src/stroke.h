#ifndef STROKE_H
#define STROKE_H

#include "main.h"

class Stroke
{
public:
    Stroke() {}
    Stroke(float fx, float fy, float fz, float tx, float ty, float tz);
    float rotation;
    float rotation1;
    glm::vec3 position;
    void draw(glm::mat4 VP);
private:
    VAO* object = NULL;
};

#endif // STROKE_H