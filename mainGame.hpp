//
//  mainGame.hpp
//  trySDL
//
//  Created by Ziwen Chen on 11/19/16.
//  Copyright © 2016 Ziwen Chen. All rights reserved.
//
#pragma once

#include <stdio.h>
#include <vector>
#include <string>

#include <SDL2/SDL.h>
#include <OpenGL/gl.h>
#include <OpenGL/glu.h>
#include <OpenGL/glext.h>
#include <OpenGL/OpenGL.h>
#include <OpenGL/gl3.h>

#include "sprite.hpp"
#include "GLSLProgram.hpp"

enum class gameState{PLAY,EXIT};


class mainGame
{
public:
    mainGame();
    ~mainGame();
    
    void run();
    


    
private:
    
    void initSystems();
    void processInput();
    void gameLoop();
    void drawGame();
    void initShaders();
    
    SDL_Window* _window;
    SDL_Surface* window_surface;
    SDL_Surface* image_surface;
    int _screenwidth;
    int _screenheight;
    
    float _time;
    
//    CGLContextObj context;
    
    
    gameState _gameState;
    
    GLSLProgram _colorProgram;
    
    std::vector<Sprite*> _sprites;
    
};


