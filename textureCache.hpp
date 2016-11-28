//
//  textureCache.hpp
//  trySDL
//
//  Created by Ziwen Chen on 11/27/16.
//  Copyright © 2016 Ziwen Chen. All rights reserved.
//

#ifndef textureCache_hpp
#define textureCache_hpp

#include <stdio.h>
#include <string>
#include <map>
#include "GLTexture.h"

class TextureCache{

public:
    TextureCache();
    ~TextureCache();
    
    
    GLTexture getTexture(std::string texturePath);
    
private:
    std::map<std::string,GLTexture> _textureMap;


};


#endif /* textureCache_hpp */
