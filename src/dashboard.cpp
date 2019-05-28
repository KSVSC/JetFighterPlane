#include "dashboard.h"
#include "main.h"

using namespace std;

Dashboard::Dashboard(float x, float y, float z, color_t color) {
    this->position = glm::vec3(x, y, z);
    this->rotation = 0;
    this->fuel =50;
    this->t1 = 0; 
    int n=1000,n1=1000;
    float t=-482, t2=0;    
    float t3=-482;
    
    GLfloat vertex_buffer_data2[10000];
    GLfloat vertex_buffer_data9[9];
    GLfloat vertex_buffer_data11[9];
    GLfloat vertex_buffer_data12[9];
    GLfloat vertex_buffer_data13[9];
    GLfloat vertex_buffer_data14[9];
    GLfloat vertex_buffer_data15[9];
    GLfloat vertex_buffer_data16[9];
    GLfloat vertex_buffer_data19[10000];
    GLfloat vertex_buffer_data20[10000];
    GLfloat vertex_buffer_data23[10000];
    GLfloat vertex_buffer_data25[25];
    GLfloat vertex_buffer_data26[25];
    GLfloat vertex_buffer_data27[25];
    GLfloat vertex_buffer_data28[25];
    GLfloat vertex_buffer_data29[25];
    GLfloat vertex_buffer_data30[25];
    GLfloat vertex_buffer_data31[25];
    GLfloat vertex_buffer_data32[25];


    // Our vertices. Three consecutive floats give a 3D vertex; Three consecutive vertices give a triangle.
    // A cube has 6 faces with 2 triangles each, so this makes 6*2=12 triangles, and 12*3 vertices
    static const GLfloat vertex_buffer_data1[] = {
    0.3,0.5,0,
    -0.3,0.5,0,
    -0.3,-0.55,0,
    0.3,-0.55,0,
    -0.3,-0.55,0,
    0.3,0.5,0
    };
   
    for(int i=0;i<9*n;i=i+9)
    {
        vertex_buffer_data2[i]=6.9f;
        vertex_buffer_data2[i+1]=-0.5f;
        vertex_buffer_data2[i+2]=0.0f;

        vertex_buffer_data2[i+3]=0.5f*(sin(3.14*t/n)) + 6.9;
        vertex_buffer_data2[i+4]=0.5f*(cos(3.14*t/n)) - 0.5;
        vertex_buffer_data2[i+5]=0.0f;

        vertex_buffer_data2[i+6]=0.5f*(sin(3.14*(t+1)/n)) + 6.9;
        vertex_buffer_data2[i+7]=0.5f*(cos(3.14*(t+1)/n)) - 0.5;
        vertex_buffer_data2[i+8]=0.0f;
        t=t+1;
    };
    
    for(int i=0;i<9*n;i=i+9)
    {
        vertex_buffer_data23[i]=6.9f;
        vertex_buffer_data23[i+1]=-0.5f;
        vertex_buffer_data23[i+2]=0.0f;

        vertex_buffer_data23[i+3]=0.55f*(sin(3.14*t3/n)) + 6.9;
        vertex_buffer_data23[i+4]=0.55f*(cos(3.14*t3/n)) - 0.5;
        vertex_buffer_data23[i+5]=0.0f;

        vertex_buffer_data23[i+6]=0.55f*(sin(3.14*(t3+1)/n)) + 6.9;
        vertex_buffer_data23[i+7]=0.55f*(cos(3.14*(t3+1)/n)) - 0.5;
        vertex_buffer_data23[i+8]=0.0f;
        t3=t3+1;
    };

    static const GLfloat vertex_buffer_data3[] = {
    0.25,-0.35,0,
    -0.25,-0.35,0,
    -0.25,-0.5,0,
    0.25,-0.5,0,
    -0.25,-0.5,0,
    0.25,-0.35,0
    };

    static const GLfloat vertex_buffer_data4[] = {
    0.25,-0.2,0,
    -0.25,-0.2,0,
    -0.25,-0.35,0,
    0.25,-0.35,0,
    -0.25,-0.35,0,
    0.25,-0.2,0
    };

    static const GLfloat vertex_buffer_data5[] = {
    0.25,-0.05,0,
    -0.25,-0.05,0,
    -0.25,-0.2,0,
    0.25,-0.2,0,
    -0.25,-0.2,0,
    0.25,-0.05,0
    };

    static const GLfloat vertex_buffer_data6[] = {
    0.25,0.1,0,
    -0.25,0.1,0,
    -0.25,-0.05,0,
    0.25,-0.05,0,
    -0.25,-0.05,0,
    0.25,0.1,0
    };

    static const GLfloat vertex_buffer_data7[] = {
    0.25,0.25,0,
    -0.25,0.25,0,
    -0.25,0.1,0,
    0.25,0.1,0,
    -0.25,0.1,0,
    0.25,0.25,0
    };

    static const GLfloat vertex_buffer_data8[] = {
    0.25,0.4,0,
    -0.25,0.4,0,
    -0.25,0.25,0,
    0.25,0.25,0,
    -0.25,0.25,0,
    0.25,0.4,0
    };

    static const GLfloat vertex_buffer_data17[] = {
    6.25,7,0,
    7.25,7,0,
    7.25,6.5,0,
    6.25,6.5,0,
    7.25,6.5,0,
    6.25,7,0
    };

    static const GLfloat vertex_buffer_data21[] = {
    6.2,7.05,0,
    7.3,7.05,0,
    7.3,6.45,0,
    6.2,6.45,0,
    7.3,6.45,0,
    6.2,7.05,0
    };

    static const GLfloat vertex_buffer_data18[] = {
    -0.3,7,0,
    0.7,7,0,
    0.7,6.5,0,
    -0.3,6.5,0,
    0.7,6.5,0,
    -0.3,7,0
    };

    static const GLfloat vertex_buffer_data22[] = {
    -0.35,7.05,0,
    0.75,7.05,0,
    0.75,6.45,0,
    -0.35,6.45,0,
    0.75,6.45,0,
    -0.35,7.05,0
    };

     for(int i=0;i<9*n1;i=i+9)
    {
        vertex_buffer_data19[i]=3.5f;
        vertex_buffer_data19[i+1]=0.0f;
        vertex_buffer_data19[i+2]=0.0f;

        vertex_buffer_data19[i+3]=0.5f*(cos(2*3.14*t2/n1)) + 3.5f;
        vertex_buffer_data19[i+4]=0.5f*(sin(2*3.14*t2/n1));
        vertex_buffer_data19[i+5]=0.0f;

        vertex_buffer_data19[i+6]=0.5f*(cos(2*3.14*(t2+1)/n1)) + 3.5f;
        vertex_buffer_data19[i+7]=0.5f*(sin(2*3.14*(t2+1)/n1));
        vertex_buffer_data19[i+8]=0.0f;
        t2=t2+1;
    };
    
    for(int i=0;i<9*n1;i=i+9)
    {
        vertex_buffer_data20[i]=3.5f;
        vertex_buffer_data20[i+1]=0.0f;
        vertex_buffer_data20[i+2]=0.0f;

        vertex_buffer_data20[i+3]=0.45f*(cos(2*3.14*t2/n1)) + 3.5f;
        vertex_buffer_data20[i+4]=0.45f*(sin(2*3.14*t2/n1));
        vertex_buffer_data20[i+5]=0.0f;

        vertex_buffer_data20[i+6]=0.45f*(cos(2*3.14*(t2+1)/n1)) + 3.5f;
        vertex_buffer_data20[i+7]=0.45f*(sin(2*3.14*(t2+1)/n1));
        vertex_buffer_data20[i+8]=0.0f;
        t2=t2+1;
    };

    static const GLfloat vertex_buffer_data24[] = {
    3.6,0.25,0,
    3.6,0.45,0,
    3.4,0.25,0,
    3.4,0.45,0,
    3.6,0.25,0,
    3.4,0.45,0,

    3.7,0.1,0,
    3.9,0.1,0,
    3.7,0.0,0,
    3.9,0.0,0,
    3.7,-0.1,0,
    3.9,-0.1,0,
    3.7,0.1,0,
    3.7,-0.1,0,

    3.3,0.1,0,
    3.3,-0.1,0,
    3.1,0.1,0,
    3.1,-0.1,0,
    3.3,-0.1,0,    
    3.2,0.0,0,    
    3.1,-0.1,0,    
    3.2,0.0,0,

    3.6,-0.25,0,
    3.4,-0.25,0,
    3.6,-0.45,0,
    3.4,-0.45,0,
    3.4,-0.25,0,
    3.4,-0.35,0,
    3.6,-0.45,0,
    3.6,-0.35,0,
    3.6,-0.35,0,
    3.4,-0.35,0
    };

    vertex_buffer_data25[0] = 3.4;
    vertex_buffer_data25[1] = 0.0;
    vertex_buffer_data25[2] = 0.0;
    vertex_buffer_data25[3] = 3.6;
    vertex_buffer_data25[4] = 0.0;
    vertex_buffer_data25[5] = 0.0;
    vertex_buffer_data25[6] = 0.45f*(sin(2*3.14*270/n)) + 3.5;
    vertex_buffer_data25[7] = 0.45f*(cos(2*3.14*270/n));      
    vertex_buffer_data25[8] = 0.0;

    for(int i = 0; i < 9; i++){
    vertex_buffer_data26[i] = vertex_buffer_data27[i] = vertex_buffer_data28[i] = vertex_buffer_data29[i] = vertex_buffer_data30[i] = vertex_buffer_data31[i] = vertex_buffer_data32[i] = vertex_buffer_data25[i];
    }

    vertex_buffer_data26[6] = 0.45f*(sin(2*3.14*90/n)) + 3.5;
    vertex_buffer_data26[7] = 0.45f*(cos(2*3.14*90/n));

    vertex_buffer_data27[6] = 0.45f*(sin(2*3.14*0/n)) + 3.5;
    vertex_buffer_data27[7] = 0.45f*(cos(2*3.14*0/n));
    
    vertex_buffer_data28[6] = 0.45f*(sin(2*3.14*-90/n)) + 3.5;
    vertex_buffer_data28[7] = 0.45f*(cos(2*3.14*-90/n));
    
    vertex_buffer_data29[6] = 0.45f*(sin(2*3.14*-270/n)) + 3.5;
    vertex_buffer_data29[7] = 0.45f*(cos(2*3.14*-270/n));

    vertex_buffer_data30[6] = 0.45f*(sin(2*3.14*-360/n)) + 3.5;
    vertex_buffer_data30[7] = 0.45f*(cos(2*3.14*-360/n));

    vertex_buffer_data31[6] = 0.45f*(sin(2*3.14*500/n)) + 3.5;
    vertex_buffer_data31[7] = 0.45f*(cos(2*3.14*500/n));

    vertex_buffer_data32[6] = 0.45f*(sin(2*3.14*360/n)) + 3.5;
    vertex_buffer_data32[7] = 0.45f*(cos(2*3.14*360/n));

    vertex_buffer_data9[0] = 6.945;
    vertex_buffer_data9[1] = -0.5;
    vertex_buffer_data9[2] = 0.0;
    vertex_buffer_data9[3] = 6.865;
    vertex_buffer_data9[4] = -0.5;
    vertex_buffer_data9[5] = 0.0;
    vertex_buffer_data9[6] = 0.5f*(sin(3.14*-360/n)) + 6.9;
    vertex_buffer_data9[7] = 0.5f*(cos(3.14*-360/n)) - 0.5;
    vertex_buffer_data9[8] = 0.0;
    
    for(int i = 0; i < 9; i++){
    vertex_buffer_data11[i] = vertex_buffer_data12[i] = vertex_buffer_data13[i] = vertex_buffer_data14[i] = vertex_buffer_data15[i] = vertex_buffer_data16[i] = vertex_buffer_data9[i];
    }

    vertex_buffer_data11[6] = 0.5f*(sin(3.14*-270/n)) + 6.9;
    vertex_buffer_data11[7] = 0.5f*(cos(3.14*-270/n)) - 0.5;

    vertex_buffer_data12[6] = 0.5f*(sin(3.14*-90/n)) + 6.9;
    vertex_buffer_data12[7] = 0.5f*(cos(3.14*-90/n)) - 0.5;
    
    vertex_buffer_data13[6] = 0.5f*(sin(3.14*0/n)) + 6.9;
    vertex_buffer_data13[7] = 0.5f*(cos(3.14*0/n)) - 0.5;
    
    vertex_buffer_data14[6] = 0.5f*(sin(3.14*90/n)) + 6.9;
    vertex_buffer_data14[7] = 0.5f*(cos(3.14*90/n)) - 0.5;

    vertex_buffer_data15[6] = 0.5f*(sin(3.14*270/n)) + 6.9;
    vertex_buffer_data15[7] = 0.5f*(cos(3.14*270/n)) - 0.5;

    vertex_buffer_data16[6] = 0.5f*(sin(3.14*360/n)) + 6.9;
    vertex_buffer_data16[7] = 0.5f*(cos(3.14*360/n)) - 0.5;

    this->object1 = create3DObject(GL_TRIANGLES, 6, vertex_buffer_data1, COLOR_DARK_BLACK, GL_FILL);
    this->object2 = create3DObject(GL_TRIANGLES, 3*n, vertex_buffer_data2, color, GL_FILL);
    this->object3 = create3DObject(GL_TRIANGLES, 6, vertex_buffer_data3, color, GL_FILL);
    this->object4 = create3DObject(GL_TRIANGLES, 6, vertex_buffer_data4, color, GL_FILL);
    this->object5 = create3DObject(GL_TRIANGLES, 6, vertex_buffer_data5, color, GL_FILL);
    this->object6 = create3DObject(GL_TRIANGLES, 6, vertex_buffer_data6, color, GL_FILL);
    this->object7 = create3DObject(GL_TRIANGLES, 6, vertex_buffer_data7, color, GL_FILL);
    this->object8 = create3DObject(GL_TRIANGLES, 6, vertex_buffer_data8, color, GL_FILL);
    this->object9 = create3DObject(GL_TRIANGLES, 3, vertex_buffer_data9, COLOR_DARK_BLACK, GL_FILL);
    this->object10 = create3DObject(GL_TRIANGLES, 6, vertex_buffer_data3, COLOR_DARK_RED, GL_FILL);
    this->object11 = create3DObject(GL_TRIANGLES, 3, vertex_buffer_data11, COLOR_DARK_BLACK, GL_FILL);
    this->object12 = create3DObject(GL_TRIANGLES, 3, vertex_buffer_data12, COLOR_DARK_BLACK, GL_FILL);
    this->object13 = create3DObject(GL_TRIANGLES, 3, vertex_buffer_data13, COLOR_DARK_BLACK, GL_FILL);
    this->object14 = create3DObject(GL_TRIANGLES, 3, vertex_buffer_data14, COLOR_DARK_BLACK, GL_FILL);
    this->object15 = create3DObject(GL_TRIANGLES, 3, vertex_buffer_data15, COLOR_DARK_BLACK, GL_FILL);
    this->object16 = create3DObject(GL_TRIANGLES, 3, vertex_buffer_data16, COLOR_DARK_BLACK, GL_FILL);
    this->object17 = create3DObject(GL_TRIANGLES, 6, vertex_buffer_data17, color, GL_FILL);
    this->object18 = create3DObject(GL_TRIANGLES, 6, vertex_buffer_data18, color, GL_FILL);
    this->object19 = create3DObject(GL_TRIANGLES, 3*n1, vertex_buffer_data19, COLOR_DARK_BLACK, GL_FILL);
    this->object20 = create3DObject(GL_TRIANGLES, 3*n1, vertex_buffer_data20, color, GL_FILL);
    this->object21 = create3DObject(GL_TRIANGLES, 6, vertex_buffer_data21, COLOR_DARK_BLACK, GL_FILL);
    this->object22 = create3DObject(GL_TRIANGLES, 6, vertex_buffer_data22, COLOR_DARK_BLACK, GL_FILL);
    this->object23 = create3DObject(GL_TRIANGLES, 3*n, vertex_buffer_data23, COLOR_DARK_BLACK, GL_FILL);
    this->object24 = create3DObject(GL_LINES, 32, vertex_buffer_data24, COLOR_DARK_BLACK, GL_FILL);
    this->object25 = create3DObject(GL_TRIANGLES, 3, vertex_buffer_data25, COLOR_DARK_BLACK, GL_FILL);
    this->object26 = create3DObject(GL_TRIANGLES, 3, vertex_buffer_data26, COLOR_DARK_BLACK, GL_FILL);
    this->object27 = create3DObject(GL_TRIANGLES, 3, vertex_buffer_data27, COLOR_DARK_BLACK, GL_FILL);
    this->object28 = create3DObject(GL_TRIANGLES, 3, vertex_buffer_data28, COLOR_DARK_BLACK, GL_FILL);
    this->object29 = create3DObject(GL_TRIANGLES, 3, vertex_buffer_data29, COLOR_DARK_BLACK, GL_FILL);
    this->object30 = create3DObject(GL_TRIANGLES, 3, vertex_buffer_data30, COLOR_DARK_BLACK, GL_FILL);
    this->object31 = create3DObject(GL_TRIANGLES, 3, vertex_buffer_data31, COLOR_DARK_BLACK, GL_FILL);
    this->object32 = create3DObject(GL_TRIANGLES, 3, vertex_buffer_data32, COLOR_DARK_BLACK, GL_FILL);
}

void Dashboard::draw(glm::mat4 VP) {
    Matrices.model = glm::mat4(0.5f);
    glm::mat4 translate = glm::translate (this->position);    // glTranslatef
    // glm::mat4 rotate    = glm::rotate((float) (this->rotation * M_PI / 180.0f), glm::vec3(1, 0, 0));
    // No need as coords centered at 0, 0, 0 of cube arouund which we waant to rotate
    // rotate          = rotate * glm::translate(glm::vec3(0, -0.6, 0));
    Matrices.model *= (translate);
    glm::mat4 MVP = VP * Matrices.model;
    glUniformMatrix4fv(Matrices.MatrixID, 1, GL_FALSE, &MVP[0][0]);
    draw3DObject(this->object1);
    draw3DObject(this->object19);
    draw3DObject(this->object20);
    draw3DObject(this->object24);

    draw3DObject(this->object23);
    draw3DObject(this->object2);
    draw3DObject(this->object21);
    draw3DObject(this->object17);
    draw3DObject(this->object22);
    draw3DObject(this->object18);
    draw3DObject(this->object3);

    if(this->fuel < 5)
        draw3DObject(this->object10);
    if(this->fuel > 10)
        draw3DObject(this->object4);
    if(this->fuel > 15)
        draw3DObject(this->object5);
    if(this->fuel > 25)
        draw3DObject(this->object6);
    if(this->fuel > 30)
        draw3DObject(this->object7);
    if(this->fuel > 45)
        draw3DObject(this->object8);

    if(this->t1 == 0)
        draw3DObject(this->object9);
    if(this->t1 == 1)
        draw3DObject(this->object11);            
    if(this->t1 == 2)
        draw3DObject(this->object12);
    if(this->t1 == 3)
        draw3DObject(this->object13);
    if(this->t1 == 4)
        draw3DObject(this->object14);
    if(this->t1 == 5)
        draw3DObject(this->object15);
    if(this->t1 == 6)
        draw3DObject(this->object16);


    if(0 < int(this->rotation) % 360 && int(this->rotation)% 360  < 45)
        draw3DObject(this->object28);
    else if(45 < int(this->rotation) % 360  && int(this->rotation) % 360  < 90)
        draw3DObject(this->object29);
    else if(90 < int(this->rotation) % 360   && int(this->rotation) % 360  < 135)
        draw3DObject(this->object30);
    else if(135 < int(this->rotation) % 360   && int(this->rotation) % 360  < 180)
        draw3DObject(this->object31);    
    else if(180 < int(this->rotation) % 360   && int(this->rotation) % 360  < 225)
        draw3DObject(this->object32);    
    else if(225 < int(this->rotation) % 360   && int(this->rotation) % 360  < 270)
        draw3DObject(this->object25);    
    else if(270 < int(this->rotation) % 360   && int(this->rotation) % 360  < 360)
        draw3DObject(this->object26);
    else
        draw3DObject(this->object27);
}

void Dashboard::set_position(float x, float y, float z) {
    this->position = glm::vec3(x, y, z);
}