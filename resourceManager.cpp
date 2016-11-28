//
//  resourceManager.cpp
//  trySDL
//
//  Created by Ziwen Chen on 11/27/16.
//  Copyright © 2016 Ziwen Chen. All rights reserved.
//

#include "resourceManager.hpp"

TextureCache resourceManager::_textureCache;

GLTexture resourceManager::getTexture (std::string texturePath){
    return _textureCache.getTexture(texturePath);

}
