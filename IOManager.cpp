//
//  IOManager.cpp
//  trySDL
//
//  Created by Ziwen Chen on 11/27/16.
//  Copyright © 2016 Ziwen Chen. All rights reserved.
//

#include "IOManager.hpp"

#include <fstream>
#include <iostream>

bool IOManager::readFileToBuffer(std::string filePath, std::vector<unsigned char>& buffer){
    std::ifstream file(filePath,std::ios::binary);
    
    if (file.fail()){
        std::cout << "fail to load file" << std::endl;
    }
    else {
        std::cout << "load file success" << std::endl;
    }
    
    file.seekg(0,std::ios::end);
    long long fileSize = file.tellg();
    file.seekg(0,std::ios::beg);
    fileSize -= file.tellg();
    
    std::printf("filesize: %lld\n",fileSize);
    
    buffer.resize(fileSize);
    file.read((char*)&buffer[0], fileSize);
    
    file.close();
    
    return true;

}
