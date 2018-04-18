//
//  AxisHelper.h
//  OpenGLHelper
//
//  Created by Mario Lubenka on 13.04.18.
//  Copyright © 2018 Mario Lubenka. All rights reserved.
//

#ifndef AxisHelper_h
#define AxisHelper_h
#include <GL/freeglut.h>

class AxisHelper {
    float lineWidth = 2.5;
    float lineLength = 10;
    float originSize = 0.01;
    bool showOrigin = true;
    
public:
    AxisHelper();
    void renderAxes();
    void setWidth(float lineWidth);
    void setLength(float lineLength);
    void setOriginSize(float originSize);
    void setShowOrigin(bool showOrigin);
};

#endif /* AxisHelper_h */
