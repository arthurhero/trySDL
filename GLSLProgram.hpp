//
//  GLSLProgram.hpp
//  trySDL
//
//  Created by Ziwen Chen on 11/24/16.
//  Copyright © 2016 Ziwen Chen. All rights reserved.
//

#ifndef GLSLProgram_hpp
#define GLSLProgram_hpp

#include <stdio.h>
#include <string>
#include <OpenGL/gl.h>


class GLSLProgram
{
public:
    GLSLProgram();
    ~GLSLProgram();
    
    void compileShaders(const std::string& vertexShaderFilePath,
                        const std::string& fragmentShaderFilePath);
    void linkShaders();
    
    void addAttribute (const std::string& attibuteName);
    
    void use();
    
    void unuse();
    
private:
    void compileShader (const std::string& filePath, GLuint& id);
    
    int _numAttributes;
    GLuint _programID;
    GLuint _vertexShaderID;
    GLuint _fragmentShaderID;


};

#endif /* GLSLProgram_hpp */
