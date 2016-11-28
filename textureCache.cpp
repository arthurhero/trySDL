//
//  textureCache.cpp
//  trySDL
//
//  Created by Ziwen Chen on 11/27/16.
//  Copyright © 2016 Ziwen Chen. All rights reserved.
//

#include "textureCache.hpp"
#include "imageLoader.hpp"
#include <iostream>

TextureCache::TextureCache(){}
TextureCache::~TextureCache(){}


GLTexture TextureCache::getTexture(std::string texturePath){
    auto mit = _textureMap.find(texturePath);
    if (mit == _textureMap.end()){
        
        GLTexture newTexture = imageLoader::loadPNG(texturePath);
        _textureMap.insert(make_pair(texturePath,newTexture));
        
        std::cout<<"added new texture!"<<std::endl;
        
        return newTexture;
    
    
    }
    std::cout<<"loaded old texture!"<<std::endl;
    return mit->second;

}
