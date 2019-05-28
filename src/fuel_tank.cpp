#include "fuel_tank.h"
#include "main.h"

Fueltank::Fueltank(float x, float y, float z,color_t color) {
    this->position = glm::vec3(x, y, z);
    this->rotation = 0;
    this->alive = 1;
    speed = 0.05;

    static const GLfloat vertex_buffer_data1[] = {
        
        -0.3f,-0.5f,-0.25f, // triangle 1 : begin
        -0.3f,-0.5f, 0.25f,
        -0.3f, 0.5f, 0.25f, // triangle 1 : end

        0.3f, 0.5f,-0.25f, // triangle 2 : begin
        -0.3f,-0.5f,-0.25f,
        -0.3f,0.5f,-0.25f, // triangle 2 : end
        
        0.3f,-0.5f, 0.25f,
        -0.3f,-0.5f,-0.25f,
        0.3f,-0.5f,-0.25f,
        
        0.3f, 0.5f,-0.25f,
        0.3f,-0.5f,-0.25f,
        -0.3f,-0.5f,-0.25f,
        
        -0.3f,-0.5f,-0.25f,
        -0.3f,0.5f, 0.25f,
        -0.3f,0.5f,-0.25f,
        
        0.3f,-0.5f, 0.25f,
        -0.3f,-0.5f, 0.25f,
        -0.3f,-0.5f,-0.25f,
        
        -0.3f,0.5f, 0.25f,
        -0.3f,-0.5f, 0.25f,
        0.3f,-0.5f, 0.25f,
        
        0.3f,0.5f, 0.25f,
        0.3f,-0.5f,-0.25f,
        0.3f,0.5f,-0.25f,
        
        0.3f,-0.5f,-0.25f,
        0.3f,0.5f, 0.25f,
        0.3f,-0.5f, 0.25f,
        
        0.3f,0.5f, 0.25f,
        0.3f,0.5f,-0.25f,
        -0.3f,0.5f,-0.25f,
        
        0.3f,0.5f, 0.25f,
        -0.3f,0.5f,-0.25f,
        -0.3f,0.5f,0.25f,
        
        0.3f,0.5f, 0.25f,
        -0.3f,0.5f, 0.25f,
        0.3f,-0.5f, 0.25f
        
    };

    static const GLfloat vertex_buffer_data2[] = {
        -0.25,0.47,0.26,
        0.25,0.47,0.26,
        0.25,0.15,0.26,
        -0.25,0.15,0.26,
        0.25,0.15,0.26,
        -0.25,0.47,0.26
    };

    static const GLfloat vertex_buffer_data3[] = {
        -0.1,-0.1,0.26,
        -0.1,-0.35,0.26,
        -0.1,-0.1,0.26,
        0.1,-0.1,0.26,
        -0.1,-0.23,0.26,
        0.1,-0.23,0.26,
    };

    this->object1 = create3DObject(GL_TRIANGLES, 12*3, vertex_buffer_data1, color, GL_FILL);
    this->object2 = create3DObject(GL_TRIANGLES, 2*3, vertex_buffer_data2, COLOR_BLACK, GL_FILL);  
    this->object3 = create3DObject(GL_LINES, 6, vertex_buffer_data3, COLOR_BLACK, GL_FILL);    
}

void Fueltank::draw(glm::mat4 VP) {
    if(this->position.y >= 3) 
    {
        this->speed *= -1;
        this->position.y += this->speed;
    }
    if(this->position.y <= -1) 
    {
        this->speed *= -1;
        this->position.y += this->speed;
    }
    Matrices.model = glm::mat4(1.0f);
    glm::mat4 translate = glm::translate (this->position);
    glm::mat4 rotate    = glm::rotate((float) (this->rotation * M_PI / 180.0f), glm::vec3(1, 0, 0));
    Matrices.model *= (translate * rotate);
    glm::mat4 MVP = VP * Matrices.model;
    glUniformMatrix4fv(Matrices.MatrixID, 1, GL_FALSE, &MVP[0][0]);
    draw3DObject(this->object1);
    draw3DObject(this->object2);
    draw3DObject(this->object3);
}

void Fueltank::set_position(float x, float y,float z) {
    this->position = glm::vec3(x, y, z);
}

void Fueltank::tick() {
    this->position.x += 0.001 ;
    if (-1 < this->position.y + this->speed < 3)
    {
        this->position.y += this->speed;
    }
}

bounding_box_t Fueltank::getboundingbox() {

    bounding_box_t temp;
    temp.x = this->position.x;
    temp.y = this->position.y;
    temp.z = this->position.z;
    temp.height = 1;
    temp.width = 0.6;
    temp.depth = 0.5;
    return temp;
}