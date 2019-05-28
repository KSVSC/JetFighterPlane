#include "fly_bullet.h"
#include "main.h"

Fly_bullet::Fly_bullet(float x, float y, float z,color_t color) {
    this->position = glm::vec3(x, y, z);
    this->rotation = 0;
    this->alive = 0;
    xspeed = 0.05;
    int n=5,i;
    float t=0;
    GLfloat vertex_buffer_data[50];
     
        for(i=0;i<9*n;i=i+9)
    {
        vertex_buffer_data[i]=1.2f;
        vertex_buffer_data[i+1]=-0.25f;
        vertex_buffer_data[i+2]=-1.0f;

        vertex_buffer_data[i+3]=0.25f*(cos(2*3.14*t/n)) + 1.2f;
        vertex_buffer_data[i+4]=0.25f*(sin(2*3.14*t/n)) - 0.25f;
        vertex_buffer_data[i+5]=-1.0f;

        vertex_buffer_data[i+6]=0.25f*(cos(2*3.14*(t+1)/n)) + 1.2f;
        vertex_buffer_data[i+7]=0.25f*(sin(2*3.14*(t+1)/n)) - 0.25f;
        vertex_buffer_data[i+8]=-1.0f;
        t=t+1;
    };

    this->object = create3DObject(GL_TRIANGLES, n*3, vertex_buffer_data, color, GL_FILL);
}

void Fly_bullet::draw(glm::mat4 VP) {
    if(this->alive)
        this->tick();
    Matrices.model = glm::mat4(1.0f);
    glm::mat4 translate = glm::translate (this->position);
    glm::mat4 rotate    = glm::rotate((float) (this->rotation * M_PI / 180.0f), glm::vec3(1, 0, 0));
    Matrices.model *= (translate * rotate);
    glm::mat4 MVP = VP * Matrices.model;
    glUniformMatrix4fv(Matrices.MatrixID, 1, GL_FALSE, &MVP[0][0]);
    draw3DObject(this->object);
}

void Fly_bullet::set_position(float x, float y, float z) {
    this->position = glm::vec3(x, y, z);
}

void Fly_bullet::tick() {
    this->position.x += xspeed;
}

bounding_box_t Fly_bullet::getboundingbox() {

    bounding_box_t temp;
    temp.x = this->position.x-1;
    temp.y = this->position.y;
    temp.z = this->position.z;
    temp.height = 0.5;
    temp.width = 0.5;
    temp.width = 0.5;
    return temp;
}