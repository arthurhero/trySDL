//
//  GLSLProgram.cpp
//  trySDL
//
//  Created by Ziwen Chen on 11/24/16.
//  Copyright © 2016 Ziwen Chen. All rights reserved.
//

#include "GLSLProgram.hpp"
#include <iostream>
#include <fstream>
#include <vector>


GLSLProgram::GLSLProgram(): _numAttributes(0), _programID(0), _vertexShaderID(0),_fragmentShaderID(0)
{


}

GLSLProgram::~GLSLProgram()
{
}

void GLSLProgram::addAttribute (const std::string& attibuteName){
    glBindAttribLocation(_programID, _numAttributes++, attibuteName.c_str());
    
    
}

GLint GLSLProgram::getUniformLocation (const std::string& attributeName){
    GLint location = glGetUniformLocation(_programID, attributeName.c_str());
    if (location == GL_INVALID_VALUE){
        std::cout << "fail to locate" << std::endl;
    }
    return location;

}

void GLSLProgram::use(){
    glUseProgram(_programID);
    for(int i = 0;i<_numAttributes;i++){
        glEnableVertexAttribArray(i);
    
    }

}

void GLSLProgram::unuse(){

    glUseProgram(0);
    
    for(int i = 0;i<_numAttributes;i++){
        glDisableVertexAttribArray(i);
        
    }
}


void GLSLProgram::compileShader (const std::string& filePath, GLuint& id){

    std::ifstream file (filePath);
    
    std::string  fileContents = "";
    std::string  line;
    
    while (std::getline(file,line)){
        fileContents += line;
        fileContents += "\n";
        
    }
    file.close();
    
    //std::cout<<fileContents<<std::endl;
    fileContents += "\0";
    
    const char* contentsPtr = fileContents.c_str();
    std::printf("%s", contentsPtr);
    glShaderSource(id, 1, &contentsPtr, nullptr);
    glCompileShader(id);
    
    GLint success = 0;
    glGetShaderiv(id, GL_COMPILE_STATUS, &success);
    
    if(success == GL_FALSE)
    {
        GLint maxLength = 0;
        glGetShaderiv(id, GL_INFO_LOG_LENGTH, &maxLength);
        
        // The maxLength includes the NULL character
        std::vector<GLchar> errorLog(maxLength);
        glGetShaderInfoLog(id, maxLength, &maxLength, &errorLog[0]);
        
        // Provide the infolog in whatever manor you deem best.
        // Exit with failure.
        glDeleteShader(id); // Don't leak the shader.
        std::printf("%s\n",&(errorLog[0]));
        return;
    }
    
    if (success == GL_FALSE){
        std::cout << "fail to compile" << std::endl;
    }
    else{
        std::cout << "compile success" << std::endl;
    }
    
    
}






void GLSLProgram::compileShaders(const std::string& vertexShaderFilePath, const std::string& fragmentShaderFilePath){
    _programID = glCreateProgram();
    _vertexShaderID = glCreateShader(GL_VERTEX_SHADER);
    _fragmentShaderID = glCreateShader(GL_FRAGMENT_SHADER);
    
    
    compileShader(vertexShaderFilePath, _vertexShaderID);
    compileShader(fragmentShaderFilePath, _fragmentShaderID);
    
}




void GLSLProgram::linkShaders(){

    glAttachShader(_programID, _vertexShaderID);
    glAttachShader(_programID, _fragmentShaderID);
    
    glLinkProgram(_programID);
    
    GLint islinked = 0;
    glGetProgramiv(_programID, GL_LINK_STATUS, &islinked);
    
    if(islinked == GL_FALSE)
    {
        GLint maxLength = 0;
        glGetProgramiv(_programID, GL_INFO_LOG_LENGTH, &maxLength);
        
        //The maxLength includes the NULL character
        std::vector<char> errorLog(maxLength);
        glGetProgramInfoLog(_programID, maxLength, &maxLength, &errorLog[0]);
        
        //The program is useless now. So delete it.
        glDeleteProgram(_programID);
        
        std::printf("%s\n",&(errorLog[0]));
    }
    
    if (islinked == GL_FALSE){
        std::cout << "fail to link" << std::endl;
    }
    else{
        std::cout << "link success" << std::endl;
    }
    
    glDetachShader(_programID, _vertexShaderID);
    glDetachShader(_programID, _fragmentShaderID);
    
    glDeleteShader(_vertexShaderID);
    glDeleteShader(_fragmentShaderID);

}


