//
//  Cube.h
//  Praktikum1
//
//  Created by Mario Lubenka on 12.04.18.
//  Copyright © 2018 Mario Lubenka. All rights reserved.
//

#ifndef Cube_h
#define Cube_h
#include "AbstractObject.h"

class Cube: public AbstractObject {
public:
    Cube(float size);
    void draw();
    void animate(int time);
protected:
    float size;
};

#endif /* Cube_h */
