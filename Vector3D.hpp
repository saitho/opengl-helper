//
//  Vector3D.hpp
//  OpenGLHelper
//
//  Created by Mario Lubenka on 18.04.18.
//  Copyright © 2018 Mario Lubenka. All rights reserved.
//

#ifndef Vector3D_hpp
#define Vector3D_hpp
#include <math.h>

class Vector3D {
public:
    Vector3D(void);
    Vector3D(float X, float Y, float Z);
    ~Vector3D(void);
    float length();
    Vector3D normalize();
    float x,y, z;
    Vector3D operator+(const Vector3D& p) const;
};

#endif /* Vector3D_hpp */
