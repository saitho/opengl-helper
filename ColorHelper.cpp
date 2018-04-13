//
//  ColorHelper.cpp
//  OpenGLHelperLib
//
//  Author: Mario Lubenka
//

#include "ColorHelper.h"

RGBColor ColorHelper::getColor(Color color) {
    switch(color) {
        case Color::RED:
            return RGBColor(255, 0, 0);
        case Color::ORANGE:
            return RGBColor(255, 165, 0);
        case Color::BLUE:
            return RGBColor(0, 0, 255);
        default:
            return RGBColor();
    }
}

RGBColor ColorHelper::getColor(std::string colorCode) {
    // Required format: # at the beginning followed by either 3 or 6 alphanumerical characters
    if (colorCode[0] != '#' || (colorCode.size() != 4 && colorCode.size() != 7)) {
        throw std::invalid_argument("Invalid format");
    }
    // remove # on first position
    colorCode.erase(0, 1);
    
    
    if (colorCode.size() == 3) {
        // format: rgb;  convert to 6 digit rrggbb format =>   #1ab == #11aabb
        colorCode[5] = colorCode[2];
        colorCode[4] = colorCode[2];
        colorCode[3] = colorCode[1];
        colorCode[2] = colorCode[1];
        colorCode[1] = colorCode[0];
    }
    
    std::string r = std::string();
    std::string g = std::string();
    std::string b = std::string();
    
    r += colorCode[0];
    r += colorCode[1];
    g += colorCode[2];
    g += colorCode[3];
    b += colorCode[4];
    b += colorCode[5];
    
    // convert hex code into float
    float rFloat = std::stoul(r, nullptr, 16);
    float gFloat = std::stoul(g, nullptr, 16);
    float bFloat = std::stoul(b, nullptr, 16);
    
    return RGBColor(rFloat, gFloat, bFloat);
}

void glColor3f( RGBColor color) {
    color.toFloatValues();
    return glColor3f(color.r, color.g, color.b);
}

void glColor3f( Color color) {
    return glColor3f(ColorHelper::getColor(color));
}

void glColor4f( Color color, float alpha) {
    return glColor4f(ColorHelper::getColor(color), alpha);
}

void glColor4f( RGBColor color, float alpha) {
    color.toFloatValues();
    return glColor4f(color.r, color.g, color.b, alpha);
}

void glClearColor( RGBColor color, float alpha ) {
    color.toFloatValues();
    return glClearColor(color.r, color.g, color.b, alpha);
}

void glClearColor( Color color, float alpha ) {
    return glClearColor(ColorHelper::getColor(color), alpha);
}
