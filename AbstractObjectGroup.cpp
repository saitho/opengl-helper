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

AbstractObject* AbstractObjectGroup::move(float x, float y, float z) {
    for (std::list<AbstractObject*>::iterator it = this->board.begin(); it != this->board.end(); it++) {
        (*it)->move(x, y, z);
    }
    return this;
}
AbstractObject* AbstractObjectGroup::translate(float x, float y, float z) {
    for (std::list<AbstractObject*>::iterator it = this->board.begin(); it != this->board.end(); it++) {
        (*it)->translate(x, y, z);
    }
    return this;
}
AbstractObject* AbstractObjectGroup::rotate(float degree) {
    for (std::list<AbstractObject*>::iterator it = this->board.begin(); it != this->board.end(); it++) {
        (*it)->rotate(degree);
    }
    return this;
}
AbstractObject* AbstractObjectGroup::rotate(float degree, RotateAxes axis) {
    for (std::list<AbstractObject*>::iterator it = this->board.begin(); it != this->board.end(); it++) {
        (*it)->rotate(degree, axis);
    }
    return this;
}

void AbstractObjectGroup::resetDrawn() {
    this->isDrawn = false;
    for (std::list<AbstractObject*>::iterator it = this->board.begin(); it != this->board.end(); it++) {
        (*it)->resetDrawn();
    }
}
