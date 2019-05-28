#include "shoot.h"
#include "main.h"
#include "aero.h"

Shoot::Shoot(float x, float y, float z, color_t color) {
    this->position = glm::vec3(x, y, z);
    this->rotation = 0;
    this->alive = 0;
    xspeed = 2.5;
    yspeed = 0;
    gravity = -0.07;
    int n=100,i;
    float t=0;

    GLfloat vertex_buffer_data[10000];
     
    for(i=0;i<9*n;i=i+9)
    {
        vertex_buffer_data[i]=0.0f;
        vertex_buffer_data[i+1]=0.0f;
        vertex_buffer_data[i+2]=0.0f;

        vertex_buffer_data[i+3]=0.25f*(cos(2*3.14*t/n));
        vertex_buffer_data[i+4]=0.25f*(sin(2*3.14*t/n));
        vertex_buffer_data[i+5]=0.0f;

        vertex_buffer_data[i+6]=0.25f*(cos(2*3.14*(t+1)/n));
        vertex_buffer_data[i+7]=0.25f*(sin(2*3.14*(t+1)/n));
        vertex_buffer_data[i+8]=0.0f;
        t=t+1;
    };

    this->object = create3DObject(GL_TRIANGLES, n*3, vertex_buffer_data, color, GL_FILL);
}

void Shoot::draw(glm::mat4 VP) {
    this->tick();    
    Matrices.model = glm::mat4(1.0f);
    glm::mat4 translate = glm::translate (this->position);
    glm::mat4 rotate    = glm::rotate((float) (this->rotation * M_PI / 180.0f), glm::vec3(1, 0, 0));
    Matrices.model *= (translate * rotate);
    glm::mat4 MVP = VP * Matrices.model;
    glUniformMatrix4fv(Matrices.MatrixID, 1, GL_FALSE, &MVP[0][0]);
    draw3DObject(this->object);
}

void Shoot::set_position(float x, float y, float z) {
    this->position = glm::vec3(x, y, z);
}

void Shoot::tick() {
    this->position.x -= this->xspeed*sin(this->rotation*M_PI/180.0f);
    this->position.z -= this->xspeed*cos(this->rotation*M_PI/180.0f);
    //  this->position.x += xspeed;
     this->yspeed += gravity;
     this->position.y += yspeed;
}

bounding_box_t Shoot::getboundingbox() {

    bounding_box_t temp;
    temp.x = this->position.x;
    temp.y = this->position.y;
    temp.z = this->position.z;
    temp.height = 0.5;
    temp.width = 0.5;
    temp.depth = 0.5;
    return temp;
}