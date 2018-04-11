//
//  RGBColor.h
//  OpenGLHelperLib
//
//  Author: Mario Lubenka
//

#ifndef RGBColor_h
#define RGBColor_h

class RGBColor {
public:
    float r;
    float g;
    float b;
    bool dirty = false;
    RGBColor();
    RGBColor(float r, float g, float b);
    void toFloatValues();
};

#endif /* RGBColor_h */
