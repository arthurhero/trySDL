//
//  imageLoader.hpp
//  trySDL
//
//  Created by Ziwen Chen on 11/27/16.
//  Copyright © 2016 Ziwen Chen. All rights reserved.
//

#ifndef imageLoader_hpp
#define imageLoader_hpp

#include <stdio.h>
#include <string>
#include "GLTexture.h"

class imageLoader{
public:
    static GLTexture loadPNG(const std::string filePath);

};


#endif /* imageLoader_hpp */
