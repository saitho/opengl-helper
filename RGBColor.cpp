//
//  RGBColor.cpp
//  OpenGLHelperLib
//
//  Author: Mario Lubenka
//

#include "RGBColor.h"

RGBColor::RGBColor(float r, float g, float b) {
    this->r = r;
    this->g = g;
    this->b = b;
}

RGBColor::RGBColor() {
}

void RGBColor::toFloatValues() {
    if(this->dirty) {
        return;
    }
    this->r = this->r/255.0f;
    this->g = this->g/255.0f;
    this->b = this->b/255.0f;
    this->dirty = true;
    return;
}
