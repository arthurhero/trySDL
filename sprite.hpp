//
//  sprite.hpp
//  trySDL
//
//  Created by Ziwen Chen on 11/22/16.
//  Copyright © 2016 Ziwen Chen. All rights reserved.
//

#ifndef sprite_hpp
#define sprite_hpp

#include <OpenGL/glu.h>
#include <stdio.h>

class Sprite
{
public:
    Sprite();
    ~Sprite();

    
    void init(float x, float y, float width, float height);
    
    
    void draw();
    
private:
    float _x;
    float _y;
    float _width;
    float _height;
    GLuint _vboID;

};

#endif /* sprite_hpp */
