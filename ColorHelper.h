//
//  ColorHelper.h
//  OpenGLHelperLib
//
//  Author: Mario Lubenka

#ifndef ColorHelper_h
#define ColorHelper_h

#include <string>
#include "RGBColor.h"
#include <GL/freeglut.h>
#include <stdexcept>

enum Color {
    RED = 0,
    BLUE = 1,
    ORANGE = 2,
};

class ColorHelper {
public:
    static RGBColor getColor(Color color);
    // colorCode is a hexadecimal color code (e.g. #ccc or #cccc for light grey)
    static RGBColor getColor(std::string colorCode);
};

void glColor3f( RGBColor color);
void glColor3f( Color color);
void glColor4f( RGBColor color, float alpha = 1.0f);
void glColor4f( Color color, float alpha = 1.0f);
void glClearColor( RGBColor color, float alpha = 1.0f );
void glClearColor( Color color, float alpha = 1.0f );

#endif /* ColorHelper_h */
