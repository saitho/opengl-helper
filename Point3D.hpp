//
//  Point3D.hpp
//  OpenGLHelper
//
//  Created by Mario Lubenka on 12.04.18.
//  Copyright © 2018 Mario Lubenka. All rights reserved.
//

#ifndef Point3D_hpp
#define Point3D_hpp

struct Point3D {
    float x = 0.;
    float y = 0.;
    float z = 0.;
    
    Point3D operator+(const Point3D& p) const
    {
        Point3D newPoint = Point3D();
        newPoint.x = x + p.x;
        newPoint.y = y + p.y;
        newPoint.z = z + p.z;
        return newPoint;
    }
};



#endif /* Point3D_hpp */
