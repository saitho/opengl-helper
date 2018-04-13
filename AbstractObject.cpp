//
//  AbstractObject.cpp
//  Praktikum1
//
//  Created by Mario Lubenka on 12.04.18.
//  Copyright © 2018 Mario Lubenka. All rights reserved.
//

#include "AbstractObject.h"

AbstractObject* AbstractObject::rotate(float degree) {
    this->rotateDegree = degree;    return this;
}
AbstractObject* AbstractObject::rotate(float degree, RotateAxes axis) {
    this->rotate(degree);
    if (axis == RotateAxes::X || axis == RotateAxes::XY || axis == RotateAxes::XZ || axis == RotateAxes::XYZ) {
        this->rotatePoint.x = 1.0;
    }
    if (axis == RotateAxes::Y || axis == RotateAxes::XY || axis == RotateAxes::YZ || axis == RotateAxes::XYZ) {
        this->rotatePoint.y = 1.0;
    }
    if (axis == RotateAxes::Z || axis == RotateAxes::XZ || axis == RotateAxes::YZ || axis == RotateAxes::XYZ) {
        this->rotatePoint.z = 1.0;
    }
    return this;
}

AbstractObject* AbstractObject::translate(Point3D point) {
    return this->translate(point.x, point.y, point.z);
}

AbstractObject* AbstractObject::move(Point3D point) {
    return this->move(point.x, point.y, point.z);
}

AbstractObject* AbstractObject::translate(float x, float y, float z) {
    this->pos.x = x;
    this->pos.y = y;
    this->pos.z = z;
    return this;
}

AbstractObject* AbstractObject::move(float x, float y, float z) {
    this->pos.x += x;
    this->pos.y += y;
    this->pos.z += z;
    return this;
}

void AbstractObject::preDraw() {
    glPushMatrix();
    glTranslatef(this->pos.x, this->pos.y, this->pos.z);
    if (
        this->rotateDegree != 0. &&
        (this->rotatePoint.x || this->rotatePoint.y || this->rotatePoint.z)
    ) {
        glRotatef(this->rotateDegree, this->rotatePoint.x, this->rotatePoint.y, this->rotatePoint.z);
    }
}

void AbstractObject::postDraw() {
    glPopMatrix();
}
