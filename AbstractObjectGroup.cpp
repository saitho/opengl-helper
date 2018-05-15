//
//  AbstractObjectGroup.cpp
//  Praktikum1
//
//  Created by Mario Lubenka on 15.05.18.
//  Copyright © 2018 Mario Lubenka. All rights reserved.
//

#include "AbstractObjectGroup.hpp"

void AbstractObjectGroup::add(AbstractObject* object) {
    this->board.push_back(object);
}


void AbstractObjectGroup::draw() {
    if (this->isDrawn) {
        return;
    }
    preDraw();
    for (std::list<AbstractObject*>::iterator it = this->board.begin(); it != this->board.end(); it++) {
        (*it)->draw();
    }
    postDraw();
}
void AbstractObjectGroup::animate(int time) {
    for (std::list<AbstractObject*>::iterator it = this->board.begin(); it != this->board.end(); it++) {
        (*it)->animate(time);
    }
}

void AbstractObjectGroup::resetDrawn() {
    this->isDrawn = false;
    for (std::list<AbstractObject*>::iterator it = this->board.begin(); it != this->board.end(); it++) {
        (*it)->resetDrawn();
    }
}

void AbstractObjectGroup::preDraw() {
    glPushMatrix();
    
    Point3D pos = this->pos;    
    glTranslatef(pos.x, pos.y, pos.z);
    if (
        this->rotateDegree != 0. &&
        (this->rotatePoint.x || this->rotatePoint.y || this->rotatePoint.z)
        ) {
        glPushMatrix();
        glRotatef(this->rotateDegree, this->rotatePoint.x, this->rotatePoint.y, this->rotatePoint.z);
    }
}

void AbstractObjectGroup::postDraw() {
    this->isDrawn = true;
    if (
        this->rotateDegree != 0. &&
        (this->rotatePoint.x || this->rotatePoint.y || this->rotatePoint.z)
        ) {
        glPopMatrix();
    }
    glPopMatrix();
}

