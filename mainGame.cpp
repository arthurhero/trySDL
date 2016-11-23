//
//  mainGame.cpp
//  trySDL
//
//  Created by Ziwen Chen on 11/19/16.
//  Copyright © 2016 Ziwen Chen. All rights reserved.
//

#include "mainGame.hpp"
#include <iostream>


mainGame::mainGame()
{
    _window = nullptr;
    _screenwidth = 500;
    _screenheight = 500;
    window_surface = NULL;
    image_surface = NULL;
    _gameState = gameState::PLAY;
}

mainGame::~mainGame()
{
    SDL_DestroyWindow(_window);
    SDL_FreeSurface(image_surface);
    SDL_Quit();
}


void mainGame::run(){
    initSystems();
    
    _sprite.init(-1, -1, 1, 1);
    gameLoop();

}

void mainGame::initSystems(){
    SDL_Init(SDL_INIT_EVERYTHING);
    
    _window = SDL_CreateWindow("Game Engine", SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, _screenwidth, _screenheight, SDL_WINDOW_OPENGL);
    
    //window_surface = SDL_GetWindowSurface(_window);
    //image_surface = SDL_LoadBMP("batman.bmp");
    
    //SDL_BlitSurface(image_surface, NULL, window_surface, NULL);
    
    //SDL_UpdateWindowSurface(_window);
    
    SDL_GLContext glContext = SDL_GL_CreateContext(_window);
    SDL_GL_SetAttribute(SDL_GL_DOUBLEBUFFER, 1.0);
    glClearColor(1.0f, 0.0f, 1.0f, 1.0f);
    

}

void mainGame::gameLoop(){
    while (_gameState != gameState::EXIT){
        processInput();
        drawGame();
    }

}

void mainGame::processInput(){
    SDL_Event evnt;
    
    while (SDL_PollEvent(&evnt)){
        switch (evnt.type) {
            case SDL_QUIT:
                _gameState = gameState::EXIT;
                break;
                
            case SDL_MOUSEMOTION:
                std::cout << evnt.motion.x << " " << evnt.motion.y << std::endl;
                
            default:
                break;
        }
    
    }
    

}


void mainGame::drawGame(){
    glClearDepth(1.0);
    glClear(GL_COLOR_BUFFER_BIT|GL_DEPTH_BUFFER_BIT);
    
    _sprite.draw();

    SDL_GL_SwapWindow(_window);

}

