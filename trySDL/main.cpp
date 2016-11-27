//
//  main.cpp
//  trySDL
//
//  Created by Ziwen Chen on 11/19/16.
//  Copyright © 2016 Ziwen Chen. All rights reserved.
//


#include <iostream>

#include "mainGame.hpp"

int main( int argc, char* args[] )
{
    std::string s = "aaa\naaa";
    s+="\n";
    s+="aaa";
    std::cout << s << std::endl;
    mainGame mainGame;
    
    mainGame.run();
        
    return 0;
}
