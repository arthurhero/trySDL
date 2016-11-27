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

#include <OpenGL/glu.h>

struct vertex {

    Position position;
    
    Color color;

};


#endif /* Vertex_h */
