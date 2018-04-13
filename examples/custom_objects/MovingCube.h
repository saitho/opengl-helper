//
//  MovingCube.h
//  Praktikum1
//
//  Created by Mario Lubenka on 12.04.18.
//  Copyright © 2018 Mario Lubenka. All rights reserved.
//

#ifndef MovingCube_h
#define MovingCube_h
#include "../../Cube.h"

class MovingCube: public Cube {
protected:
    Point3D moveVector;
public:
    MovingCube(float size);
    void animate(int time);
    
    Point3D getRandomDirectionVector();
};

#endif /* MovingCube_h */
