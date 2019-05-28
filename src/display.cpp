#include "display.h"
#include "main.h"
#include <cstring>

Display::Display(float x, float y, float z)
{
    this->position = glm::vec3(x, y, z);
    altitude = 0;
    digslen = 0;
}

void Display::update(int altitude) {
    this->altitude = altitude;
    char altitudestr[50];
    sprintf(altitudestr, "%d", altitude);
    digslen = strlen(altitudestr);
    for (int i = digslen - 1; i >= 0; i--) {
        digs[i] = Number(altitudestr[i], 4 - 0.3*(digslen - i) + position.x, position.y, position.z);
    }
}

int Display::view() {
    return altitude;
}

void Display::reset(){
    altitude =0;
}

void Display::draw(glm::mat4 VP) {
    for (int i = 0; i < digslen; i++) digs[i].draw(VP);
}

void Display::set_position(float x, float y, float z){
    this->position = glm::vec3(x, y, z);
}