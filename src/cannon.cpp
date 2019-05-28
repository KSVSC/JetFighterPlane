#include "cannon.h"
#include "main.h"

Cannon::Cannon(float x, float y, float z, color_t color) {
    this->position = glm::vec3(x, y, z);
    this->rotation = 0;
    this->alive = 1;
    this->killed = 0;
    this->arrow = 0;

    speed = 0.1;
    int n=100,i;
    float t=0;


    // Our vertices. Three consecutive floats give a 3D vertex; Three consecutive vertices give a triangle.
    // A cube has 6 faces with 2 triangles each, so this makes 6*2=12 triangles, and 12*3 vertices
    static const GLfloat vertex_buffer_data1[] = {
        -0.7f,-0.25f,-0.5f, // triangle 1 : begin
        -0.7f,-0.25f, 0.5f,
        -0.7f, 0.45f, 0.5f, // triangle 1 : end

        0.7f, 0.45f,-0.5f, // triangle 2 : begin
        -0.7f,-0.25f,-0.5f,
        -0.7f,0.45f,-0.5f, // triangle 2 : end
        
        0.7f,-0.25f, 0.5f,
        -0.7f,-0.25f,-0.5f,
        0.7f,-0.25f,-0.5f,
        
        0.7f, 0.45f,-0.5f,
        0.7f,-0.25f,-0.5f,
        -0.7,-0.25f,-0.5f,
        
        -0.7f,-0.25f,-0.5f,
        -0.7f,0.45f, 0.5f,
        -0.7f,0.45f,-0.5f,
        
        0.7f,-0.25f, 0.5f,
        -0.7f,-0.25f, 0.5f,
        -0.7f,-0.25f,-0.5f,
        
        -0.7f,0.45f, 0.5f,
        -0.7f,-0.25f, 0.5f,
        0.7f,-0.25f, 0.5f,
        
        0.7f,0.45f, 0.5f,
        0.7f,-0.25f,-0.5f,
        0.7f,0.45f,-0.5f,
        
        0.7f,-0.25f,-0.5f,
        0.7f,0.45f, 0.5f,
        0.7f,-0.25f, 0.5f,
        
        0.7f,0.45f, 0.5f,
        0.7f,0.45f,-0.5f,
        -0.7f,0.45f,-0.5f,
        
        0.7f,0.45f, 0.5f,
        -0.7f,0.45f,-0.5f,
        -0.7f,0.45f,0.5f,
        
        0.7f,0.45f, 0.5f,
        -0.7f,0.45f, 0.5f,
        0.7f,-0.25f, 0.5f

    };


    static const GLfloat vertex_buffer_data2[] = {
        -0.6f,0.45f,-0.4f, // triangle 1 : begin
        -0.6f,0.45f, 0.4f,
        -0.6f, 0.95f, 0.4f, // triangle 1 : end

        0.6f, 0.95f,-0.4f, // triangle 2 : begin
        -0.6f,0.45f,-0.4f,
        -0.6f,0.45f,-0.4f, // triangle 2 : end
        
        0.6f,0.45f, 0.4f,
        -0.6f,0.45f,-0.4f,
        0.6f,0.45f,-0.4f,
        
        0.6f, 0.95f,-0.4f,
        0.6f,0.45f,-0.4f,
        -0.6f,0.45f,-0.4f,
        
        -0.6f,0.45f,-0.4f,
        -0.6f,0.95f, 0.4f,
        -0.6f,0.95f,-0.4f,
        
        0.6f,0.45f, 0.4f,
        -0.6f,0.45f, 0.4f,
        -0.6f,0.45f,-0.4f,
        
        -0.6f,0.95f, 0.4f,
        -0.6f,0.45f, 0.4f,
        0.6f,0.45f, 0.4f,
        
        0.6f,0.95f, 0.4f,
        0.6f,0.45f,-0.4f,
        0.6f,0.95f,-0.4f,
        
        0.6f,0.45f,-0.4f,
        0.6f,0.95f, 0.4f,
        0.6f,0.45f, 0.4f,
        
        0.6f,0.95f, 0.4f,
        0.6f,0.95f,-0.4f,
        -0.6f,0.95f,-0.4f,
        
        0.6f,0.95f, 0.4f,
        -0.6f,0.95f,-0.4f,
        -0.6f,0.95f, 0.4f,
        
        0.6f,0.95f, 0.4f,
        -0.6f,0.95f, 0.4f,
        0.6f,0.45f, 0.4f

    };
    
    static const GLfloat vertex_buffer_data3[] = {
        0.6f,0.4f,-0.15f, // triangle 1 : begin
        0.6f,0.4f, 0.15f,
        1.15f, 0.45f, 0.15f, // triangle 1 : end

        1.15f, 0.45f,-0.15f, // triangle 2 : begin
        0.6f,0.4f,-0.15f,
        0.6f,0.45f,-0.15f, // triangle 2 : end
        
        1.15f,0.4f, 0.15f,
        0.6f,0.4f,-0.15f,
        1.15f,0.4f,-0.15f,
        
        1.15f, 0.45f,-0.15f,
        1.15f,0.4f,-0.15f,
        0.6f,0.4f,-0.15f,
        
        0.6f,0.45f,-0.15f,
        0.6f,0.45f, 0.15f,
        0.6f,0.45f,-0.15f,
        
        1.15f,0.4f, 0.15f,
        0.6f,0.4f, 0.15f,
        0.6f,0.4f,-0.15f,
        
        0.6f,0.45f, 0.15f,
        0.6f,0.4f, 0.15f,
        1.15f,0.4f, 0.15f,
        
        1.15f,0.45f, 0.15f,
        1.15f,0.4f,-0.15f,
        1.15f,0.45f,-0.15f,
        
        1.15f,0.4f,-0.15f,
        1.15f,0.45f, 0.15f,
        1.15f,0.4f, 0.15f,
        
        1.15f,0.45f, 0.15f,
        1.15f,0.45f,-0.15f,
        0.6f,0.45f,-0.15f,
        
        1.15f,0.45f, 0.15f,
        0.6f,0.45f,-0.15f,
        0.6f,0.45f,0.15f,
        
        1.15f,0.45f, 0.15f,
        0.6f,0.45f, 0.15f,
        1.15f,0.4f, 0.15f

    };

    GLfloat vertex_buffer_data4[10000];
     
    for(i=0;i<9*n;i=i+9)
    {
        vertex_buffer_data4[i]=0.0f + 0.1;
        vertex_buffer_data4[i+1]=0.1f;
        vertex_buffer_data4[i+2]=0.0f;

        vertex_buffer_data4[i+3]=2.5f*(cos(2*3.14*t/n)) + 0.1;
        vertex_buffer_data4[i+4]=0.1f;
        vertex_buffer_data4[i+5]=2.5f*(sin(2*3.14*t/n));

        vertex_buffer_data4[i+6]=2.5f*(cos(2*3.14*(t+1)/n)) + 0.1;
        vertex_buffer_data4[i+7]=0.1f;
        vertex_buffer_data4[i+8]=2.5f*(sin(2*3.14*(t+1)/n));
        t=t+1;
    };

    static const GLfloat vertex_buffer_data5[] = {
        -0.1f,2.5f,0.1f, // triangle 1 : begin
        0.1f,2.5f, 0.1f,
        -0.1f, 3.0f ,0.1f, // triangle 1 : end
       
        0.1f, 2.5f,0.1f, // triangle 2 : begin
        -0.1f, 3.0f,0.1f,
        0.1f,  3.0f,0.1f, // triangle 2 : end
       
       
        -0.1f,2.5f,-0.1f, // triangle 1 : begin
        0.1f, 2.5f,-0.1f ,
        -0.1f, 3.0f,-0.1f, // triangle 1 : end
       
        0.1f, 2.5f,-0.1f, // triangle 2 : begin
        -0.1f, 3.0f,-0.1f,
        0.1f,  3.0f,-0.1f, // triangle 2 : end
       

        0.1f, 2.5f, 0.1f,
        0.1f, 3.0f, 0.1f,
        0.1f, 3.0f,-0.1f,

        0.1f,2.5f, 0.1f,
        0.1f,3.0f,-0.1f,
        0.1f,2.5f,-0.1f,


        -0.1f,2.5f, 0.1f,
        -0.1f,3.0f, 0.1f,
        -0.1f,3.0f,-0.1f,

        -0.1f,2.5f, 0.1f,
        -0.1f, 3.0f,-0.1f,
        -0.1f,2.5f,-0.1f,


        -0.1f, 2.5f, 0.1f,
        0.1f,  2.5f, 0.1f,
        -0.1f, 2.5f,-0.1f,

        -0.1f,2.5f,-0.1f,
        0.1f,  2.5f, 0.1f,
        0.1f, 2.5f,-0.1f,


        -0.1f,3.0f, 0.1f,
        0.1f, 3.0f, 0.1f,
        -0.1f,3.0f,-0.1f,

        -0.1f,3.0f,-0.1f,
        0.1f, 3.0f, 0.1f,
        0.1f, 3.0f,-0.1f
    };

    static const GLfloat vertex_buffer_data6[] = {

        -0.25f, 2.5f,0.1f,
         0.25f, 2.5f,0.1f,
         0.0f, 2.25f, 0.0f,

        -0.25f,2.5f,-0.1f,
        -0.25f,2.5f, 0.1f,
         0.0f,2.25,  0.0f,

        0.25f,2.5f, 0.1f,
        0.25f,2.5f,-0.1f,
        0.0f,2.25f,  0.0f,

        -0.25f,2.5f,-0.1f,
         0.25f,2.5f,-0.1f,
         0.0f,2.25f,  0.0f
    };
    
    this->object1 = create3DObject(GL_TRIANGLES, 12*3, vertex_buffer_data1, color, GL_FILL);
    this->object2 = create3DObject(GL_TRIANGLES, 12*3, vertex_buffer_data2, COLOR_DARK_BLUE, GL_FILL);
    this->object3 = create3DObject(GL_TRIANGLES, 12*3, vertex_buffer_data3, color, GL_FILL);
    this->object4 = create3DObject(GL_TRIANGLES, 3*n, vertex_buffer_data4, COLOR_GREEN, GL_FILL);
    this->object5 = create3DObject(GL_TRIANGLES, 12*3, vertex_buffer_data5, COLOR_DARK_RED, GL_FILL);
    this->object6 = create3DObject(GL_TRIANGLES, 4*3, vertex_buffer_data6, COLOR_DARK_RED, GL_FILL);
}

void Cannon::draw(glm::mat4 VP) {
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
    draw3DObject(this->object4);
    if(this->arrow){
        draw3DObject(this->object5);
        draw3DObject(this->object6);
    }
}

void Cannon::set_position(float x, float y, float z) {
    this->position = glm::vec3(x, y, z);
}

void Cannon::tick(){
    this->rotation += speed;
}

bounding_box_t Cannon::getboundingbox() {

    bounding_box_t temp;
    temp.x = this->position.x;
    temp.y = this->position.y;
    temp.z = this->position.z;
    temp.height = 1.2;
    temp.width = 5;
    temp.depth = 5;
    return temp;
}