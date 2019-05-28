#include "aero.h"
#include "main.h"
using namespace std;


Aero::Aero(float x, float y, float z, color_t color) {
    this->position = glm::vec3(x, y, z);
    this->MyVector = glm::mat4(1.0f);
    this->rotation_x = 0;
    this->rotation_y = 0;
    this->rotation_z = 0;
    this->speed = 0.5;
    yaw = 0;
    roll = 0;
    pitch = 0;
    // Our vertices. Three consecutive floats give a 3D vertex; Three consecutive vertices give a triangle.
    // A cube has 6 faces with 2 triangles each, so this makes 6*2=12 triangles, and 12*3 vertices
    static const GLfloat vertex_buffer_data1[] = {
        -0.25f,0.15f,-1.5f, // triangle 1 : begin
        0.25f,0.15f, -1.5f,
        -0.25f, 0.15f, 1.5f, // triangle 1 : end
       
        0.25f, 0.15f,-1.5f, // triangle 2 : begin
        -0.25f,0.15f,1.5f,
        0.25f, 0.15f,1.5f, // triangle 2 : end
       
       
        -0.25f,-0.15f,-1.5f, // triangle 1 : begin
        0.25f,-0.15f, -1.5f,
        -0.25f,-0.15f, 1.5f, // triangle 1 : end
       
        0.25f,-0.15f,-1.5f, // triangle 2 : begin
        -0.25f,-0.15f,1.5f,
        0.25f,-0.15f,1.5f, // triangle 2 : end
       

        0.25f,0.15f, -1.5f,
        0.25f,0.15f,1.5f,
        0.25f,-0.15f,1.5f,

        0.25f, 0.15f,-1.5f,
        0.25f,-0.15f,1.5f,
        0.25f,-0.15f,-1.5f,


        -0.25f,0.15f, -1.5f,
        -0.25f,0.15f,1.5f,
        -0.25f,-0.15f,1.5f,

        -0.25f, 0.15f,-1.5f,
        -0.25f,-0.15f,1.5f,
        -0.25f,-0.15f,-1.5f,


        -0.25f,0.15f,-1.5f,
        0.25f, 0.15f, -1.5f,
        -0.25f,-0.15f,-1.5f,

        -0.25f,-0.15f,-1.5f,
        0.25f,0.15f, -1.5f,
        0.25f,-0.15f,-1.5f,


        -0.25f,0.15f,1.5f,
        0.25f, 0.15f,1.5f,
        -0.25f,-0.15f,.5f,

        -0.25f,-0.15f,1.5f,
        0.25f,0.15f,1.5f,
        0.25f,-0.15f,1.5f
    };

    static const GLfloat vertex_buffer_data2[] = {

        0.25f,0.15f,-1.15f,
        0.25f, 0.15f,-0.15f,
        2.5f,0.0f,0.25f,

        0.25f,-0.15f,-1.15f,
        0.25f,0.15f,-1.15f,
        2.5f,0.0f,0.25f,

        0.25f,-0.15f,-1.15f,
        0.25f, -0.15f,-0.15f,
        2.5f,0.0f,0.25f,

        0.25f,-0.15f,-0.15f,
        0.25f,0.15f,-0.15f,
        2.5f,0.0f,0.25f
    };

    static const GLfloat vertex_buffer_data3[] = {

        -0.25f,0.15f,-1.15f,
        -0.25f, 0.15f,-0.15f,
        -2.5f,0.0f,0.25f,

        -0.25f,-0.15f,-1.15f,
        -0.25f,0.15f,-1.15f,
        -2.5f,0.0f,0.25f,

        -0.25f,-0.15f,-1.15f,
        -0.25f, -0.15f,-0.15f,
        -2.5f,0.0f,0.25f,

        -0.25f,-0.15f,-0.15f,
        -0.25f,0.15f,-0.15f,
        -2.5f,0.0f,0.25f
    };

    static const GLfloat vertex_buffer_data4[] = {

        -0.75f,0.15f,2.5f,
        0.75f, 0.15f,2.5f,
        0.0f,0.0f,1.0f,

        -0.75f,-0.15f,2.5f,
        -0.75f,0.15f,2.5f,
        0.0f,0.0f,1.0f,

        0.75f,0.15f,2.5f,
        0.75f,-0.15f,2.5f,
        0.0f,0.0f,1.0f,

        -0.75f,-0.15f,2.5f,
        0.75f,-0.15f,2.5f,
        0.0f,0.0f,1.0f
    };

    static const GLfloat vertex_buffer_data5[] = {

        -0.25f,0.15f,-1.5f,
        0.25f, 0.15f,-1.5f,
        0.0f,0.0f,-2.0f,

        -0.25f,-0.15f,-1.5f,
        -0.25f,0.15f,-1.5f,
        0.0f,0.0f,-2.0f,

        0.25f,0.15f,-1.5f,
        0.25f,-0.15f,-1.5f,
        0.0f,0.0f,-2.0f,

        -0.25f,-0.15f,-1.5f,
        0.25f,-0.15f,-1.5f,
        0.0f,0.0f,-2.0f
    };

    this->object1 = create3DObject(GL_TRIANGLES, 12*3, vertex_buffer_data1, color, GL_FILL);
    this->object2 = create3DObject(GL_TRIANGLES, 4*3, vertex_buffer_data2, COLOR_RED, GL_FILL);
    this->object3 = create3DObject(GL_TRIANGLES, 4*3, vertex_buffer_data3, COLOR_RED, GL_FILL);
    this->object4 = create3DObject(GL_TRIANGLES, 4*3, vertex_buffer_data4, COLOR_RED, GL_FILL);
    this->object5 = create3DObject(GL_TRIANGLES, 9*3, vertex_buffer_data5, COLOR_RED, GL_FILL);
}

void Aero::draw(glm::mat4 VP) {
    Matrices.model = glm::mat4(1.0f);
    glm::mat4 translate = glm::translate (this->position);    // glTranslatef
    // No need as coords centered at 0, 0, 0 of cube arouund which we waant to rotate
    // rotate          = rotate * glm::translate(glm::vec3(0, 0, 0));
    glm::mat4 rotate_yaw = glm::mat4(1.0f);
    glm::mat4 rotate_pitch = glm::mat4(1.0f);
    glm::mat4 rotate_roll = glm::mat4(1.0f);
    glm::mat4 rotate;

    // if(this->yaw)
        rotate_yaw = glm::rotate((float) (this->rotation_z * M_PI / 180.0f), glm::vec3(0, 0, 1));
    // else if(this->pitch)
        rotate_pitch = glm::rotate((float) (this->rotation_x * M_PI / 180.0f), glm::vec3(1, 0, 0));
    // else if(this->roll)
        rotate_roll = glm::rotate((float) (this->rotation_y * M_PI / 180.0f), glm::vec3(0, 1, 0));
    
    this->MyVector    *= rotate_yaw * rotate_pitch * rotate_roll;
    rotate = this->MyVector;
    Matrices.model *= (translate * rotate);
    glm::mat4 MVP = VP * Matrices.model;
    glUniformMatrix4fv(Matrices.MatrixID, 1, GL_FALSE, &MVP[0][0]);
    draw3DObject(this->object5);
    draw3DObject(this->object4);
    draw3DObject(this->object2);
    draw3DObject(this->object3);
    draw3DObject(this->object1);

    this->yaw = 0;
    this->roll = 0;
    this->pitch = 0;
    this->rotation_x = 0;
    this->rotation_y = 0;
    this->rotation_z = 0;
}

void Aero::set_position(float x, float y, float z) {
    this->position = glm::vec3(x, y, z);
}

void Aero::lefttick() {
    this->rotation_y += speed;
}

void Aero::uptick() {
    this->speed = 0.35;
    this->position.y += speed;
}

void Aero::righttick() {
    this->rotation_y -= speed;
}

void Aero::downtick() {
    this->speed = 0.25;
    if(position.y > 0)
    this->position.y -= speed;
}

void Aero::frwdtick(){
    this-> speed = 0.5;
    glm::mat4 v = glm::translate (this->position);
    glm::vec4 final_pos = (v * MyVector * glm::vec4(0, 0, -this->speed, 1));
    this->position = glm::vec3(final_pos.x, final_pos.y, final_pos.z);
   }

void Aero::rttick(){
    this->speed = 0.55;
    this->rotation_z -= speed;
}

void Aero::lttick(){
    this->speed = 0.55;
    this->rotation_z += speed;
}

bounding_box_t Aero::getboundingbox() {

    bounding_box_t temp;
    temp.x = this->position.x;
    temp.y = this->position.y;
    temp.z = this->position.z;
    temp.height = 0.3;
    temp.width = 5;
    temp.depth = 4.5;
    return temp;
}