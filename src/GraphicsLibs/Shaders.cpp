#include <glad/glad.h>
#include <GLFW/glfw3.h>
#include <iostream>
#include <cmath>
#include "Shaders.hpp"

Shader::Shader(const char* ShaderSource,GLint ShaderProgram,int Type)
{
    _ShaderSource = ShaderSource;
    _ShaderProgram = ShaderProgram;
    _Type = Type;
    _Shader = glCreateShader(Type);
}

void Shader::Activate()
{
    glShaderSource(_Shader,1,&_ShaderSource,nullptr);
    glCompileShader(_Shader);
    glAttachShader(_ShaderProgram,_Shader);
}

void Shader::Delete()
{
    glDeleteShader(_Shader);
}