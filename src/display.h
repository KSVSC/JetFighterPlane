#ifndef DISPLAY_H
#define DISPLAY_H

#include "number.h"

class Display
{
public:
    Display(){}
    Display(float x,float y,float z);
    glm::vec3 position;
    void draw(glm::mat4 VP);
    void update(int altitude);
    int view();
    void reset();
    void set_position(float x, float y, float z);

private:
    int altitude, digslen;
    Number digs[50];
};

#endif // DISPLAY_H