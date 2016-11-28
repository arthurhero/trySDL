//
//  sprite.cpp
//  trySDL
//
//  Created by Ziwen Chen on 11/22/16.
//  Copyright © 2016 Ziwen Chen. All rights reserved.
//

#include "sprite.hpp"
#include "Vertex.h"


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

void Sprite::init(float x, float y, float width, float height, std::string texturePath)
{
    _x=x;
    _y=y;
    _width=width;
    _height=height;
    _texture = resourceManager::getTexture(texturePath);
    
    if (_vboID==0){
        glGenBuffers(1, &_vboID);
    }
    vertex vertexData[6];
    
    //first triangle
    
    vertexData[0].setPosition(x+width, y+height);
    vertexData[0].setUV(1.0, 1.0);
    
    vertexData[1].setPosition(x, y+height);
    vertexData[1].setUV(0.0, 1.0);
    
    vertexData[2].setPosition(x, y);
    vertexData[2].setUV(0.0,0.0);
    
    
    //second triangle
    
    vertexData[3].setPosition(x, y);
    vertexData[3].setUV(0.0, 0.0);
    
    vertexData[4].setPosition(x+width, y);
    vertexData[4].setUV(1.0, 0.0);
    
    vertexData[5].setPosition(x+width, y+height);
    vertexData[5].setUV(1.0,1.0);
    
    
    for (int i=0;i<6;i++){
        
        vertexData[i].setColor(255, 100, 255, 255);
    
    }
    
    vertexData[1].setColor(255, 100, 100, 255);
    vertexData[4].setColor(100,100,255,255);
 
    
    glBindBuffer(GL_ARRAY_BUFFER, _vboID);
    
    glBufferData(GL_ARRAY_BUFFER, sizeof(vertexData), vertexData, GL_STATIC_DRAW);
    
    glBindBuffer(GL_ARRAY_BUFFER, 0);
    

}

void Sprite::draw()
{
    glBindTexture(GL_TEXTURE_2D, _texture.id);
    glBindBuffer(GL_ARRAY_BUFFER, _vboID);
    
    glEnableVertexAttribArray(0);
    
    glVertexAttribPointer(0, 2, GL_FLOAT, GL_FALSE, sizeof(vertex), (void*)__offsetof(vertex, position));
    glVertexAttribPointer(1, 4, GL_UNSIGNED_BYTE, GL_TRUE, sizeof(vertex), (void*)__offsetof(vertex, color));
    glVertexAttribPointer(2, 2, GL_FLOAT, GL_FALSE, sizeof(vertex), (void*)__offsetof(vertex, uv));
    
    
    glDrawArrays(GL_TRIANGLES, 0, 6);
    
    
    glDisableVertexAttribArray(0);

    glBindBuffer(GL_ARRAY_BUFFER, 0);
}
