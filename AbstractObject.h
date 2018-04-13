//
//  AbstractObject.h
//  Praktikum1
//
//  Created by Mario Lubenka on 12.04.18.
//  Copyright © 2018 Mario Lubenka. All rights reserved.
//

#ifndef AbstractObject_h
#define AbstractObject_h
#include <GL/freeglut.h>

enum RotateAxes {
    X = 0,
    Y = 1,
    Z = 2,
    XY = 3,
    YZ = 4,
    XZ = 5,
    XYZ = 6
};

typedef struct {
    float x = 0.;
    float y = 0.;
    float z = 0.;
} Point3D;

class AbstractObject {
protected:
    void preDraw();
    void postDraw();
public:
    float rotateDegree = 0.;
    Point3D rotatePoint;
    Point3D pos;
    
    virtual void draw() = 0;
    virtual void animate(int time) = 0;
    
    AbstractObject* move(Point3D point);
    AbstractObject* move(float x, float y, float z);
    AbstractObject* translate(Point3D point);
    AbstractObject* translate(float x, float y, float z);
    AbstractObject* rotate(float degree);
    AbstractObject* rotate(float degree, RotateAxes axis);
};

#endif /* AbstractObject_h */
