//
//  Vertex.h
//  trySDL
//
//  Created by Ziwen Chen on 11/26/16.
//  Copyright © 2016 Ziwen Chen. All rights reserved.
//

#ifndef Vertex_h
#define Vertex_h

struct Position{
    float x;
    float y;
};

struct Color{
    GLubyte r;
    GLubyte g;
    GLubyte b;
    GLubyte a;
};

struct UV{
    float u;
    float v;

};

#include <OpenGL/glu.h>

struct vertex {

    Position position;
    
    Color color;
    
    UV uv;
    
    void setPosition (float x, float y){
        position.x = x;
        position.y = y;
    }
    void setColor (GLubyte r,GLubyte g,GLubyte b,GLubyte a){
        color.r = r;
        color.g = g;
        color.b = b;
        color.a = a;
    }
    void setUV (float u, float v){
        uv.u = u;
        uv.v = v;
    }

};


#endif /* Vertex_h */
