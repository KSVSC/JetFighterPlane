#include "parachutes.h"
#include "main.h"

Parachutes::Parachutes(float x, float y, float z, color_t color) {
    this->position = glm::vec3(x, y, z);
    this->rotation = 0;
    this->alive = 1;
    this->killed = 0;
    speed = 0.1;
    speed1 = 0.015;
    int n=7,i;
    float t=0;


    // Our vertices. Three consecutive floats give a 3D vertex; Three consecutive vertices give a triangle.
    // A cube has 6 faces with 2 triangles each, so this makes 6*2=12 triangles, and 12*3 vertices
    static const GLfloat vertex_buffer_data1[] = {
        -0.5f,-1.95f,-0.5f, // triangle 1 : begin
        -0.5f,-1.95f, 0.5f,
        -0.5f,-1.25f, 0.5f, // triangle 1 : end

        0.5f, -1.25f,-0.5f, // triangle 2 : begin
        -0.5f,-1.95f,-0.5f,
        -0.5f,-1.25f,-0.5f, // triangle 2 : end
        
        0.5f,-1.95f, 0.5f,
        -0.5f,-1.95f,-0.5f,
        0.5f,-1.95f,-0.5f,
        
        0.5f, -1.25f,-0.5f,
        0.5f,-1.95f,-0.5f,
        -0.5,-1.95f,-0.5f,
        
        -0.5f,-1.95f,-0.5f,
        -0.5f,-1.25f, 0.5f,
        -0.5f,-1.25f,-0.5f,
        
        0.5f,-1.95f, 0.5f,
        -0.5f,-1.95f, 0.5f,
        -0.5f,-1.95f,-0.5f,
        
        -0.5f,-1.25f, 0.5f,
        -0.5f,-1.95f, 0.5f,
        0.5f,-1.95f, 0.5f,
        
        0.5f,-1.25f, 0.5f,
        0.5f,-1.95f,-0.5f,
        0.5f,-1.25f,-0.5f,
        
        0.5f,-1.95f,-0.5f,
        0.5f,-1.25f, 0.5f,
        0.5f,-1.95f, 0.5f,
        
        0.5f,-1.25f, 0.5f,
        0.5f,-1.25f,-0.5f,
        -0.5f,-1.25f,-0.5f,
        
        0.5f,-1.25f, 0.5f,
        -0.5f,-1.25f,-0.5f,
        -0.5f,-1.25f,0.5f,
        
        0.5f,-1.25f, 0.5f,
        -0.5f,-1.25f, 0.5f,
        0.5f,-1.95f, 0.5f

    };

    GLfloat vertex_buffer_data2[100];
     
    for(i=0;i<9*n;i=i+9)
    {
        vertex_buffer_data2[i]= 0.0f;
        vertex_buffer_data2[i+1]= 1.5;
        vertex_buffer_data2[i+2]= 0.0f;

        vertex_buffer_data2[i+3]= 1.5 * (cos(2*3.14*t/n));
        vertex_buffer_data2[i+4]= 0.0f;
        vertex_buffer_data2[i+5]= 1.5 * (sin(2*3.14*t/n));

        vertex_buffer_data2[i+6]= 1.5 * (cos(2*3.14*(t+1)/n));
        vertex_buffer_data2[i+7]= 0.0f;
        vertex_buffer_data2[i+8]= 1.5 * (sin(2*3.14*(t+1)/n));
        t=t+1;
    }

     static const GLfloat vertex_buffer_data3[] = {

        1.5 * (cos(2*3.14*2/6)), 0.0f, 1.5 * (sin(2*3.14*2/6)),
        0.0f, -1.25f, 0.0f,
    
        1.5 * (cos(2*3.14*5/6)), 0.0f, 1.5 * (sin(2*3.14*5/6)),
        0.0f, -1.25f, 0.0f
     };
    
    this->object1 = create3DObject(GL_TRIANGLES, 12*3, vertex_buffer_data1, COLOR_BROWN, GL_FILL);
    this->object2 = create3DObject(GL_TRIANGLES, 3*n, vertex_buffer_data2, color, GL_FILL);
    this->object3 = create3DObject(GL_LINES, 5, vertex_buffer_data3, COLOR_DARK_RED, GL_FILL);
}

void Parachutes::draw(glm::mat4 VP) {
    if(this->position.y >= 5) 
    {
        this->speed1 *= -1;
        this->position.y += this->speed1;
    }
    if(this->position.y <= 2) 
    {
        this->speed1 *= -1;
        this->position.y += this->speed1;
    }
    Matrices.model = glm::mat4(0.5f);
    glm::mat4 translate = glm::translate (this->position);    // glTranslatef
    glm::mat4 rotate    = glm::rotate((float) (this->rotation * M_PI / 180.0f), glm::vec3(0, 1, 0));
    // No need as coords centered at 0, 0, 0 of cube arouund which we waant to rotate
    // rotate          = rotate * glm::translate(glm::vec3(0, -0.6, 0));
    Matrices.model *= (translate * rotate);
    glm::mat4 MVP = VP * Matrices.model;
    glUniformMatrix4fv(Matrices.MatrixID, 1, GL_FALSE, &MVP[0][0]);
    draw3DObject(this->object1);
    draw3DObject(this->object2);
    draw3DObject(this->object3);
}

void Parachutes::set_position(float x, float y, float z) {
    this->position = glm::vec3(x, y, z);
}

void Parachutes::tick(){
    if (2 < this->position.y + this->speed1 < 5)
    {
        this->position.y += this->speed1;
    }
}

bounding_box_t Parachutes::getboundingbox() {

    bounding_box_t temp;
    temp.x = this->position.x;
    temp.y = this->position.y;
    temp.z = this->position.z;
    temp.height = 3.45;
    temp.width = 1.5;
    temp.depth = 1.5;
    return temp;
}