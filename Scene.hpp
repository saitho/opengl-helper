//
//  Scene.hpp
//  OpenGLHelper
//
//  Created by Mario Lubenka on 17.04.18.
//  Copyright © 2018 Mario Lubenka. All rights reserved.
//

#ifndef Scene_hpp
#define Scene_hpp

#include <vector>
#include <list>
#include "ColorHelper.h"
#include "AxisHelper.h"
#include "Camera.hpp"
#include "AbstractObject.h"
#include <GL/freeglut.h>

class Scene {
    int activeCamera = 0;
    std::vector<Camera*> cameras;
    std::list<AbstractObject*> board;
    bool showAxes = false;
        
public:
    ~Scene();
    Camera* getActiveCamera();
    void setActiveCamera(int index);
    void add(AbstractObject* object);
    void add(Camera* camera);
    const std::list<AbstractObject*>& getBoard();
    void display(); // DisplayFunc
    void reshape(int width, int height); // ReshapeFunc
    void animate(int value);
    void setShowAxes(bool showAxes);
};

#endif /* Scene_hpp */
