#ifndef SHADERS_H
#define SHADERS_H
#include <glad/glad.h>
#include <GLFW/glfw3.h>
#include <iostream>
#include <cmath>

class Shader
{
    public:
        Shader(const char* ShaderSource,GLint ShaderProgram,int Type);
        void Activate();
        void Delete();
    
    private:
        GLint _Shader;
        GLint _ShaderProgram;
        const char* _ShaderSource;
        int _Type;
};

#endif SHADERS_H