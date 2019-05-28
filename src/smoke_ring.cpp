#include "smoke_ring.h"
#include "main.h"

Smokering::Smokering(float x, float y, float z, color_t color) {
    this->position = glm::vec3(x, y, z);
    this->rotation = 0;
    this->killed = 0;
    int n=100,i;
    float t=0;


    // Our vertices. Three consecutive floats give a 3D vertex; Three consecutive vertices give a triangle.
    // A cube has 6 faces with 2 triangles each, so this makes 6*2=12 triangles, and 12*3 vertices
    GLfloat vertex_buffer_data[10000];
     
    for(i=0;i<9*n;i=i+9)
    {
        vertex_buffer_data[i]=3.0f*(cos(2*3.14*t/n));
        vertex_buffer_data[i+1]=3.0f*(sin(2*3.14*t/n));
        vertex_buffer_data[i+2]=0.0f;

        vertex_buffer_data[i+3]=3.0f*(cos(2*3.14*(t+1)/n));
        vertex_buffer_data[i+4]=3.0f*(sin(2*3.14*(t+1)/n));
        vertex_buffer_data[i+5]=0.0;

        vertex_buffer_data[i+6]=3.0f*(cos(2*3.14*(t)/n));
        vertex_buffer_data[i+7]=3.0f*(sin(2*3.14*(t)/n));
        vertex_buffer_data[i+8]=1.5f;
        t=t+1;
    };   
    
    this->object1 = create3DObject(GL_TRIANGLES, n*3, vertex_buffer_data, color, GL_FILL);
}

void Smokering::draw(glm::mat4 VP) {
    Matrices.model = glm::mat4(0.5f);
    glm::mat4 translate = glm::translate (this->position);    // glTranslatef
    glm::mat4 rotate    = glm::rotate((float) (this->rotation * M_PI / 180.0f), glm::vec3(0, 1, 0));
    // No need as coords centered at 0, 0, 0 of cube arouund which we waant to rotate
    // rotate          = rotate * glm::translate(glm::vec3(0, -0.6, 0));
    Matrices.model *= (translate * rotate);
    glm::mat4 MVP = VP * Matrices.model;
    glUniformMatrix4fv(Matrices.MatrixID, 1, GL_FALSE, &MVP[0][0]);
    draw3DObject(this->object1);
}

void Smokering::set_position(float x, float y, float z) {
    this->position = glm::vec3(x, y, z);
}

bounding_box_t Smokering::getboundingbox() {

    bounding_box_t temp;
    temp.x = this->position.x;
    temp.y = this->position.y;
    temp.z = this->position.z;
    temp.height = 6;
    temp.width = 6;
    temp.depth = 1.2;
    return temp;
}