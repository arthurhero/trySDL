//
//  imageLoader.cpp
//  trySDL
//
//  Created by Ziwen Chen on 11/27/16.
//  Copyright © 2016 Ziwen Chen. All rights reserved.
//

#include "imageLoader.hpp"
#include "picoPNG.hpp"
#include "IOManager.hpp"
#include <iostream>

GLTexture imageLoader::loadPNG(const std::string filePath){
    
    GLTexture texture = {};
    
    std::vector<unsigned char>in;
    std::vector<unsigned char>out;
    
    unsigned long height;
    unsigned long width;
    
    
    IOManager::readFileToBuffer(filePath, in);
    
    int errorCode = decodePNG(out, width, height, &(in[0]), in.size());
    
    if (errorCode != 0){
        std::cout << "fail to decode " << std::to_string(errorCode) <<std::endl;
    }
    else {
        std::cout << "decode success" << std::endl;
    }
    
    glEnable(GL_TEXTURE_2D);
    glGenTextures(1, &(texture.id));
    glBindTexture(GL_TEXTURE_2D, texture.id);
    
    glTexImage2D(GL_TEXTURE_2D, 0, GL_RGBA, width, height, 0, GL_RGBA, GL_UNSIGNED_BYTE, &(out[0]));
    
    glTexParameterf(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_REPEAT);
    glTexParameterf(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_REPEAT);
    glTexParameterf(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);
    glTexParameterf(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR_MIPMAP_LINEAR);
    
    glGenerateMipmap(GL_TEXTURE_2D);
    
    glBindTexture(GL_TEXTURE_2D, 0);
    
    texture.width = width;
    texture.height = height;

    return texture;
}
