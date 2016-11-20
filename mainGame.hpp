//
//  mainGame.hpp
//  trySDL
//
//  Created by Ziwen Chen on 11/19/16.
//  Copyright © 2016 Ziwen Chen. All rights reserved.
//
#pragma once

#include <stdio.h>

#include <SDL2/SDL.h>
#include <OpenGL/OpenGL.h>

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
    
    SDL_Window* _window;
    SDL_Surface* window_surface;
    SDL_Surface* image_surface;
    int _screenwidth;
    int _screenheight;
    
    gameState _gameState;
    
};


