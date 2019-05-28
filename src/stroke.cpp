#include "stroke.h"
#include "main.h"
using namespace std;

Stroke::Stroke(float fx, float fy,float fz, float tx, float ty, float tz)
{
    this->rotation1 = 0;
    if (tx == fx) rotation = ty > fy ? M_PI/2 : -M_PI/2;
    else if (ty == fy) rotation = tx > fx ? 0 : M_PI;
    else rotation = atan((ty-fy)/(tx-fx));
    position = glm::vec3(fx, fy, 0);
    GLfloat vertex_buffer_data [] = {
        0, 0, 0,
        0.2, 0, 0
    };
    this->object = create3DObject(GL_LINES, 2, vertex_buffer_data, COLOR_BLACK, GL_FILL);
}


void Stroke::draw(glm::mat4 VP) {
    if (!this->object) return;
    Matrices.model = glm::mat4(1.0f);
    glm::mat4 translate = glm::translate (this->position);        // glTranslatef
    // glm::mat4 rotate1    = glm::rotate((float) (this->rotation * M_PI / 180.0f), glm::vec3(0, 0, 1));
    glm::mat4 rotate = glm::rotate(this->rotation, glm::vec3(0,0,1));
    Matrices.model *= translate * rotate;
    glm::mat4 MVP = VP * Matrices.model;
    glUniformMatrix4fv(Matrices.MatrixID, 1, GL_FALSE, &MVP[0][0]);
    draw3DObject(this->object);
}