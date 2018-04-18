//
//  Camera.hpp
//  OpenGLHelper
//
//  Created by Mario Lubenka on 17.04.18.
//  Copyright © 2018 Mario Lubenka. All rights reserved.
//

#ifndef Camera_hpp
#define Camera_hpp
#include "Vector3D.hpp"

class Camera {
protected:
    Vector3D cameraPosition;
    Vector3D cameraLookAt;
    Vector3D cameraVertical = Vector3D(0, 1, 0);
    
public:
    void moveBy(float x, float y, float z);
    void moveBy(Vector3D point);
    void moveTo(float x, float y, float z);
    void moveTo(Vector3D point);
    void lookAt(float x, float y, float z);
    void lookAt(Vector3D point);
    void lookAtRel(float x, float y, float z);
    void lookAtRel(Vector3D point);
    
    void setVerticalVector(float x, float y, float z);
    void setVerticalVector(Vector3D point);
    
    Vector3D getCameraPosition();
    Vector3D getCameraLookAt();
    Vector3D getCameraVertical();
};

#endif /* Camera_hpp */
