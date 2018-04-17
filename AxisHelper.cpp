//
//  AxisHelper.cpp
//  OpenGLHelper
//
//  Created by Mario Lubenka on 13.04.18.
//  Copyright © 2018 Mario Lubenka. All rights reserved.
//

#include "AxisHelper.h"

AxisHelper::AxisHelper() {
}

void AxisHelper::setLength(float lineLength) {
    this->lineLength = lineLength;
}

void AxisHelper::setWidth(float lineWidth) {
    this->lineWidth = lineWidth;
}

void AxisHelper::setOriginSize(float originSize) {
    this->originSize = originSize;
}

void AxisHelper::setShowOrigin(bool showOrigin) {
    this->showOrigin = showOrigin;
}

void AxisHelper::renderAxes() {
    glPushMatrix();
    glLineWidth(this->lineWidth);
    // x axis (red)
    glColor3f(1., 0., 0.);
    glBegin(GL_LINES);
    glVertex3f(-this->lineLength, 0., 0.);
    glVertex3f(this->lineLength, 0., 0.);
    glEnd();
    
    // y axis (green)
    glColor3f(0., 1., 0.);
    glBegin(GL_LINES);
    glVertex3f(0.,-this->lineLength,  0.);
    glVertex3f(0., this->lineLength, 0.);
    glEnd();
    glColor3f(0., 0., 1.);
    
    // z axis (blue)
    glBegin(GL_LINES);
    glVertex3f(0.0, 0., -this->lineLength);
    glVertex3f(0., 0., this->lineLength);
    glEnd();
    
    if (this->showOrigin) {
        glBegin(GL_POLYGON);
        glColor3f(1., 1., 1.);
        glutSolidSphere(this->originSize, 10, 10);
        glEnd();
    }
    glPopMatrix();
}
