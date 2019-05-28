#include "volcano.h"
#include "main.h"

Volcano::Volcano(float x, float y, float z, color_t color) {
    this->position = glm::vec3(x, y, z);
    this->rotation = 0;
    this->killed =0;

    int i,n=10,n1=100;
    float t =0,t1=0;

    GLfloat vertex_buffer_data[10000];
    
    for(i=0;i<9*n;i=i+9)
    {
        vertex_buffer_data[i]=0.0f;
        vertex_buffer_data[i+1]= 1.5;
        vertex_buffer_data[i+2]=0.0f;

        vertex_buffer_data[i+3]=1.5 * (cos(2*3.14*t/n));
        vertex_buffer_data[i+4]=0.0f;
        vertex_buffer_data[i+5]=1.5 * (sin(2*3.14*t/n));

        vertex_buffer_data[i+6]=1.5 * (cos(2*3.14*(t+1)/n));
        vertex_buffer_data[i+7]=0.0f;
        vertex_buffer_data[i+8]=1.5 * (sin(2*3.14*(t+1)/n));
        t=t+1;
    }
     
    GLfloat vertex_buffer_data2[10000];
     
    for(i=0;i<9*n1;i=i+9)
    {
        vertex_buffer_data2[i]=0.0f;
        vertex_buffer_data2[i+1]=-0.2f;
        vertex_buffer_data2[i+2]=0.0f;

        vertex_buffer_data2[i+3]=3.5f*(cos(2*3.14*t1/n1));
        vertex_buffer_data2[i+4]=-0.2f;
        vertex_buffer_data2[i+5]=3.5f*(sin(2*3.14*t1/n1));

        vertex_buffer_data2[i+6]=3.5f*(cos(2*3.14*(t1+1)/n1));
        vertex_buffer_data2[i+7]=-0.2f;
        vertex_buffer_data2[i+8]=3.5f*(sin(2*3.14*(t1+1)/n1));
        t1=t1+1;
    };
    this->object = create3DObject(GL_TRIANGLES, 3*n, vertex_buffer_data, color, GL_FILL);
    this->object1 = create3DObject(GL_TRIANGLES, 3*n1, vertex_buffer_data2, COLOR_DARK_GREEN, GL_FILL);
}

void Volcano::draw(glm::mat4 VP) {
    Matrices.model = glm::mat4(1.0f);
    glm::mat4 translate = glm::translate (this->position);    // glTranslatef
    glm::mat4 rotate    = glm::rotate((float) (this->rotation * M_PI / 180.0f), glm::vec3(1, 0, 0));
    // No need as coords centered at 0, 0, 0 of cube arouund which we waant to rotate
    // rotate          = rotate * glm::translate(glm::vec3(0, -0.6, 0));
    Matrices.model *= (translate * rotate);
    glm::mat4 MVP = VP * Matrices.model;
    glUniformMatrix4fv(Matrices.MatrixID, 1, GL_FALSE, &MVP[0][0]);
    draw3DObject(this->object);
    draw3DObject(this->object1);
}

void Volcano::set_position(float x, float y, float z) {
    this->position = glm::vec3(x, y, z);
}

bounding_box_t Volcano::getboundingbox() {

    bounding_box_t temp;
    temp.x = this->position.x;
    temp.y = this->position.y + 5;
    temp.z = this->position.z;
    temp.height = 1.5;
    temp.width = 7.0;
    temp.depth = 7.0;
    return temp;
}