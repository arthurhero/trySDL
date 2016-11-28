//
//  resourceManager.hpp
//  trySDL
//
//  Created by Ziwen Chen on 11/27/16.
//  Copyright © 2016 Ziwen Chen. All rights reserved.
//

#ifndef resourceManager_hpp
#define resourceManager_hpp

#include <stdio.h>
#include "GLTexture.h"
#include "textureCache.hpp"
#include <string>

class resourceManager{
    
public:
    static GLTexture getTexture (std::string texturePath);
    
private:
    static TextureCache _textureCache;
    
    
};



#endif /* resourceManager_hpp */
