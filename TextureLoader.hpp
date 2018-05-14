//
//  TextureLoader.hpp
//  Praktikum1
//
//  Created by Mario Lubenka on 13.05.18.
//  Copyright © 2018 Mario Lubenka. All rights reserved.
//

#ifndef TextureLoader_hpp
#define TextureLoader_hpp
#include <GL/freeglut.h>
#include <iostream>
#include <string>
#include <map>

class TextureLoader {
    static std::map<std::string, GLuint> textures;
public:
    static GLuint loadBMP(const std::string key, const std::string imagepath);
    static GLuint getTexture(const std::string key);
};

#endif /* TextureLoader_hpp */
