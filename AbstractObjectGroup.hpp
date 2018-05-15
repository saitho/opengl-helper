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
protected:
    std::list<AbstractObject*> board;
    void preDraw();
    void postDraw();
    
public:
    void add(AbstractObject* object);
    void clearBoard();
    void draw();
    void animate(int time);
    void resetDrawn();
};

#endif /* AbstractObjectGroup_hpp */
