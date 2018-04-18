//
//  Vector3D.cpp
//  OpenGLHelper
//
//  Created by Mario Lubenka on 18.04.18.
//  Copyright © 2018 Mario Lubenka. All rights reserved.
//

#include "Vector3D.hpp"

Vector3D::Vector3D(void)
{
}

Vector3D::Vector3D(float X, float Y, float Z){
    this->x = X;
    this->y = Y;
    this->z = Z;
}

// Returns the length of the vector
float Vector3D::length(){
    return sqrt(x * x + y * y + z * z);
}

// Normalizes the vector
Vector3D Vector3D::normalize(){
    Vector3D vector;
    float length = this->length();
    
    if(length != 0){
        vector.x = x/length;
        vector.y = y/length;
        vector.z = z/length;
    }
    
    return vector;
}

Vector3D Vector3D::operator+(const Vector3D& p) const
{
    Vector3D newPoint = Vector3D();
    newPoint.x = this->x + p.x;
    newPoint.y = this->y + p.y;
    newPoint.z = this->z + p.z;
    return newPoint;
}

Vector3D::~Vector3D(void)
{
}
