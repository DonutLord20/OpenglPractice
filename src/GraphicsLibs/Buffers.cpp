#include <glad/glad.h>
#include <GLFW/glfw3.h>
#include <iostream>
#include <cmath>
#include "Buffers.hpp"
#include<vector>

VertexArrayObject::VertexArrayObject()
{
    glGenVertexArrays(1,&_VAO);
}

void VertexArrayObject::Bind()
{
    glBindVertexArray(_VAO);
}

void VertexArrayObject::CreateAttribePointer(GLuint Location,GLint Size,GLint Type,GLint IsNormalised,GLsizei Stride,void* Start)
{
    glVertexAttribPointer(Location,Size,Type,IsNormalised,Stride,Start);
    glEnableVertexAttribArray(Location);
}

void VertexArrayObject::UnBind()
{
    glBindVertexArray(0);
}

void VertexArrayObject::Delete()
{
    glDeleteVertexArrays(1,&_VAO);
}


BufferObject::BufferObject(int Amount,int Type)
{
    _Type = Type;
    _Amount = Amount;
    glGenBuffers(_Amount,&_BufferObj);
}

void BufferObject::Bind()
{
    glBindBuffer(_Type,_BufferObj);
}

void BufferObject::PassData(GLfloat* Data,size_t Size,int Usage)
{
    glBufferData(_Type,Size,Data,Usage);
}

void BufferObject::PassData(GLuint* Data,size_t Size,int Usage)
{
    glBufferData(_Type,Size,Data,Usage);
}

void BufferObject::PassData(GLboolean* Data,size_t Size,int Usage)
{
    glBufferData(_Type,Size,Data,Usage);
}

void BufferObject::PassData(std::vector<GLfloat>* Data,size_t Size,int Usage)
{
    glBufferData(_Type,Size,Data,Usage);
}

void BufferObject::Delete()
{
    glDeleteBuffers(_Amount,&_BufferObj);
}


