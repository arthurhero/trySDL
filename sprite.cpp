//
//  sprite.cpp
//  trySDL
//
//  Created by Ziwen Chen on 11/22/16.
//  Copyright © 2016 Ziwen Chen. All rights reserved.
//

#include "sprite.hpp"


Sprite::Sprite()
{
    _vboID=0;
}

Sprite::~Sprite()
{
    if (_vboID!=0){
        glDeleteBuffers(1, &_vboID);
    }
}

void Sprite::init(float x, float y, float width, float height)
{
    _x=x;
    _y=y;
    _width=width;
    _height=height;
    
    if (_vboID==0){
        glGenBuffers(1, &_vboID);
    }
    float vertexData[6*2];
    
    //first triangle
    
    vertexData[0]=x+width;
    vertexData[1]=y+width;
    vertexData[2]= x;
    vertexData[3]=y+height;
    vertexData[4]= x;
    vertexData[5]= y;
    
    //second triangle
    
    vertexData[0]=x;
    vertexData[1]=y;
    vertexData[2]= x+width;
    vertexData[3]=y;
    vertexData[4]= x+width;
    vertexData[5]= y+height;
    
    glBindBuffer(GL_ARRAY_BUFFER, _vboID);
    
    glBufferData(GL_ARRAY_BUFFER, sizeof(vertexData), vertexData, GL_STATIC_DRAW);
    
    glBindBuffer(GL_ARRAY_BUFFER, 0);
    

}

void Sprite::draw()
{
    glBindBuffer(GL_ARRAY_BUFFER, _vboID);
    
    glEnableVertexAttribArray(0);
    
    glVertexAttribPointer(0, 2, GL_FLOAT, GL_FALSE, 0, 0);
    
    glDrawArrays(GL_TRIANGLES, 0, 6);
    
    
    glDisableVertexAttribArray(0);

    glBindBuffer(GL_ARRAY_BUFFER, 0);
}