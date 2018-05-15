//
//  AbstractObjectGroup.hpp
//  Praktikum1
//
//  Created by Mario Lubenka on 15.05.18.
//  Copyright © 2018 Mario Lubenka. All rights reserved.
//

#ifndef AbstractObjectGroup_hpp
#define AbstractObjectGroup_hpp
#include "Point3D.hpp"
#include "AbstractObject.h"
#include <list>

class AbstractObjectGroup : public AbstractObject {
    std::list<AbstractObject*> board;
    
public:
    void add(AbstractObject* object);
    void draw();
    void animate(int time);
    
    AbstractObject* move(Point3D point);
    AbstractObject* move(float x, float y, float z);
    AbstractObject* translate(Point3D point);
    AbstractObject* translate(float x, float y, float z);
    AbstractObject* rotate(float degree);
    AbstractObject* rotate(float degree, RotateAxes axis);
    void resetDrawn();
};

#endif /* AbstractObjectGroup_hpp */
