#include "ball.h"
#include "main.h"

Ball::Ball(float x, float y, float z, color_t color) {
    this->position = glm::vec3(x, y, z);
    this->rotation = 0;
    speed = 0.01;
    this->alive = 1;
    // Our vertices. Three consecutive floats give a 3D vertex; Three consecutive vertices give a triangle.
    // A cube has 6 faces with 2 triangles each, so this makes 6*2=12 triangles, and 12*3 vertices
    static const GLfloat vertex_buffer_data1[] = {
        
        -0.5f,-0.5f,-0.25f, // triangle 1 : begin
        -0.5f,-0.5f, 0.25f,
        -0.5f, 0.5f, 0.25f, // triangle 1 : end

        0.5f, 0.5f,-0.25f, // triangle 2 : begin
        -0.5f,-0.5f,-0.25f,
        -0.5f,0.5f,-0.25f, // triangle 2 : end
        
        0.5f,-0.5f, 0.25f,
        -0.5f,-0.5f,-0.25f,
        0.5f,-0.5f,-0.25f,
        
        0.5f, 0.5f,-0.25f,
        0.5f,-0.5f,-0.25f,
        -0.5f,-0.5f,-0.25f,
        
        -0.5f,-0.5f,-0.25f,
        -0.5f,0.5f, 0.25f,
        -0.5f,0.5f,-0.25f,
        
        0.5f,-0.5f, 0.25f,
        -0.5f,-0.5f, 0.25f,
        -0.5f,-0.5f,-0.25f,
        
        -0.5f,0.5f, 0.25f,
        -0.5f,-0.5f, 0.25f,
        0.5f,-0.5f, 0.25f,
        
        0.5f,0.5f, 0.25f,
        0.5f,-0.5f,-0.25f,
        0.5f,0.5f,-0.25f,
        
        0.5f,-0.5f,-0.25f,
        0.5f,0.5f, 0.25f,
        0.5f,-0.5f, 0.25f,
        
        0.5f,0.5f, 0.25f,
        0.5f,0.5f,-0.25f,
        -0.5f,0.5f,-0.25f,
        
        0.5f,0.5f, 0.25f,
        -0.5f,0.5f,-0.25f,
        -0.5f,0.5f,0.25f,
        
        0.5f,0.5f, 0.25f,
        -0.5f,0.5f, 0.25f,
        0.5f,-0.5f, 0.25f
        
    };

    static const GLfloat vertex_buffer_data2[] = {
        -0.25,0.5,0.26,
        0.25,0.5,0.26,
        0.25,-0.5,0.26,
        -0.25,-0.5,0.26,
        0.25,-0.5,0.26,
        -0.25,0.5,0.26,

        -0.5,0.25,0.26,
        0.5,0.25,0.26,
        0.5,-0.25,0.26,
        -0.5,-0.25,0.26,
        0.5,-0.25,0.26,
        -0.5,0.25,0.26
    };

    this->object1 = create3DObject(GL_TRIANGLES, 12*3, vertex_buffer_data1, COLOR_RED, GL_FILL);
    this->object2 = create3DObject(GL_TRIANGLES, 12, vertex_buffer_data2, color, GL_FILL);
}

void Ball::draw(glm::mat4 VP) {
    Matrices.model = glm::mat4(1.0f);
    glm::mat4 translate = glm::translate (this->position);    // glTranslatef
    glm::mat4 rotate    = glm::rotate((float) (this->rotation * M_PI / 180.0f), glm::vec3(1, 0, 0));
    // No need as coords centered at 0, 0, 0 of cube arouund which we waant to rotate
    // rotate          = rotate * glm::translate(glm::vec3(0, -0.6, 0));
    Matrices.model *= (translate * rotate);
    glm::mat4 MVP = VP * Matrices.model;
    glUniformMatrix4fv(Matrices.MatrixID, 1, GL_FALSE, &MVP[0][0]);
    draw3DObject(this->object1);
    draw3DObject(this->object2);
}

void Ball::set_position(float x, float y, float z) {
    this->position = glm::vec3(x, y, z);
}

bounding_box_t Ball::getboundingbox() {

    bounding_box_t temp;
    temp.x = this->position.x;
    temp.y = this->position.y;
    temp.z = this->position.z;
    temp.height = 1;
    temp.width = 1;
    temp.depth = 0.5;
    return temp;
}