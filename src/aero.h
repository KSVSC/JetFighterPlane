#include "main.h"

#ifndef AERO_H
#define AERO_H

class Aero {
public:
    Aero() {}
    Aero(float x, float y, float z, color_t color);
    glm::vec3 position;
    glm::mat4 MyVector;
    float rotation_x;
    float rotation_z;
    float rotation_y;
    void draw(glm::mat4 VP);
    void set_position(float x, float y, float z);
    void lefttick();
    void righttick();
    void uptick();
    void downtick();
    void frwdtick();
    void lttick();
    void rttick();
    bool yaw;
    bool pitch;
    bool roll;
    bounding_box_t getboundingbox();
    double speed;
private:
    VAO *object1;
    VAO *object2;
    VAO *object3;
    VAO *object4;
    VAO *object5;        
};

#endif // AERO_H
