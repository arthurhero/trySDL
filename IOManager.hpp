//
//  IOManager.hpp
//  trySDL
//
//  Created by Ziwen Chen on 11/27/16.
//  Copyright © 2016 Ziwen Chen. All rights reserved.
//

#ifndef IOManager_hpp
#define IOManager_hpp

#include <stdio.h>
#include <vector>
#include <string>

class IOManager {

public:
    static bool readFileToBuffer(std::string filePath, std::vector<unsigned char>& buffer);

};


#endif /* IOManager_hpp */
