//
//  MovingCube.cpp
//  Praktikum1
//
//  Created by Mario Lubenka on 12.04.18.
//  Copyright © 2018 Mario Lubenka. All rights reserved.
//

#include "MovingCube.h"
#include <cstdlib>
#include <iostream>

MovingCube::MovingCube(float size): Cube(size) {
    this->moveVector = this->getRandomDirectionVector();
}

void MovingCube::animate(int time) {
    this->rotateDegree = this->rotateDegree - 1.;
    if ( this->rotateDegree <= 0.0) {
        this->rotateDegree += 360.0;
    }
    if (time % 1000 == 0) {
        this->move(this->moveVector);
    }
}

Point3D MovingCube::getRandomDirectionVector() {
    Point3D point = Point3D();
    point.x = static_cast<float>(rand() % 2) - 1.0f;
    point.y = static_cast<float>(rand() % 2) - 1.0f;
    point.z = static_cast<float>(rand() % 2) - 1.0f;
    
    return point;
}
