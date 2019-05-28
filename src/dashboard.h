
#include "main.h"

#ifndef DASHBOARD_H
#define DASHBOARD_H

class Dashboard {
public:
    Dashboard() {}
    Dashboard(float x, float y, float z, color_t color);
    glm::vec3 position;
    float rotation;
    float fuel;
    int t1;
    void draw(glm::mat4 VP);
    void set_position(float x, float y, float z);
private:
    VAO *object1;
    VAO *object2;
    VAO *object3;
    VAO *object4;
    VAO *object5;
    VAO *object6;
    VAO *object7;
    VAO *object8;
    VAO *object9;
    VAO *object10;
    VAO *object11;
    VAO *object12;
    VAO *object13;
    VAO *object14;
    VAO *object15;
    VAO *object16;
    VAO *object17;
    VAO *object18;
    VAO *object19;
    VAO *object20;
    VAO *object21;
    VAO *object22;
    VAO *object23;
    VAO *object24;
    VAO *object25;
    VAO *object26;
    VAO *object27;
    VAO *object28;
    VAO *object29;
    VAO *object30;
    VAO *object31;
    VAO *object32;
};

#endif // DASHBOARD_H
