#include "arrow.h"
#include "main.h"

Arrow::Arrow(float x, float y, float z, color_t color) {
    this->position = glm::vec3(x, y, z);
    this->rotation = 0;

    // Our vertices. Three consecutive floats give a 3D vertex; Three consecutive vertices give a triangle.
    // A cube has 6 faces with 2 triangles each, so this makes 6*2=12 triangles, and 12*3 vertices
    static const GLfloat vertex_buffer_data1[] = {
        -0.2f,0.15f,-0.5f, // triangle 1 : begin
        0.2f,0.15f, -0.5f,
        -0.2f, 0.15f, 0.5f, // triangle 1 : end
       
        0.2f, 0.15f,-0.5f, // triangle 2 : begin
        -0.2f,0.15f,0.5f,
        0.2f, 0.15f,0.5f, // triangle 2 : end
       
       
        -0.2f,-0.15f,-0.5f, // triangle 1 : begin
        0.2f,-0.15f, -0.5f,
        -0.2f,-0.15f, 0.5f, // triangle 1 : end
       
        0.2f,-0.15f,-0.5f, // triangle 2 : begin
        -0.2f,-0.15f,0.5f,
        0.2f,-0.15f,0.5f, // triangle 2 : end
       

        0.2f,0.15f, -0.5f,
        0.2f,0.15f,0.5f,
        0.2f,-0.15f,0.5f,

        0.2f, 0.15f,-0.5f,
        0.2f,-0.15f,0.5f,
        0.2f,-0.15f,-0.5f,


        -0.2f,0.15f, -0.5f,
        -0.2f,0.15f,0.5f,
        -0.2f,-0.15f,0.5f,

        -0.2f, 0.15f,-0.5f,
        -0.2f,-0.15f,0.5f,
        -0.2f,-0.15f,-0.5f,


        -0.2f,0.15f,-0.5f,
        0.2f, 0.15f, -0.5f,
        -0.2f,-0.15f,-0.5f,

        -0.2f,-0.15f,-0.5f,
        0.2f,0.15f, -0.5f,
        0.2f,-0.15f,-0.5f,


        -0.2f,0.15f,0.5f,
        0.2f, 0.15f,0.5f,
        -0.2f,-0.15f,0.5f,

        -0.2f,-0.15f,0.5f,
        0.2f,0.15f,0.5f,
        0.2f,-0.15f,0.5f
    };

    static const GLfloat vertex_buffer_data2[] = {

        -0.5f,0.15f,-0.5f,
        0.5f, 0.15f,-0.5f,
        0.0f,0.0f,-1.0f,

        -0.5f,-0.15f,-0.5f,
        -0.5f,0.15f,-0.5f,
        0.0f,0.0f,-1.0f,

        0.5f,0.15f,-0.5f,
        0.5f,-0.15f,-0.5f,
        0.0f,0.0f,-1.0f,

        -0.5f,-0.15f,-0.5f,
        0.5f,-0.15f,-0.5f,
        0.0f,0.0f,-1.0f
    };

    this->object1 = create3DObject(GL_TRIANGLES, 12*3, vertex_buffer_data1, color, GL_FILL);
    this->object2 = create3DObject(GL_TRIANGLES, 4*3, vertex_buffer_data2, color, GL_FILL);
}

void Arrow::draw(glm::mat4 VP) {
    Matrices.model = glm::mat4(1.0f);
    glm::mat4 translate = glm::translate (this->position);    // glTranslatef
    // No need as coords centered at 0, 0, 0 of cube arouund which we waant to rotate
    // rotate          = rotate * glm::translate(glm::vec3(0, 0, 0));
    glm::mat4 rotate;

    rotate = glm::rotate((float) (this->rotation * M_PI / 180.0f), glm::vec3(0, 1, 0));
    
    Matrices.model *= (translate * rotate);
    glm::mat4 MVP = VP * Matrices.model;
    glUniformMatrix4fv(Matrices.MatrixID, 1, GL_FALSE, &MVP[0][0]);
    draw3DObject(this->object2);
    draw3DObject(this->object1);
    // this->rotation = 0;
}

void Arrow::set_position(float x, float y, float z) {
    this->position = glm::vec3(x, y, z);
}

void Arrow::lefttick() {
    this->rotation += 20;
}

void Arrow::righttick() {
    this->rotation -= 20;
}