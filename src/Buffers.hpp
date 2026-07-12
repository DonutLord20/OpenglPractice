#ifndef BUFFERS_H
#define BUFFERS_H

#include <glad/glad.h>
#include <GLFW/glfw3.h>
#include <iostream>
#include <cmath>


class VertexArrayObject
{
    public:
        VertexArrayObject();
        void Bind();
        void CreateAttribePointer(GLuint Loacation,GLint Size,GLint Type,GLint IsNormalised,GLint Stride,void* Start);
        void UnBind();
        void Delete();

    private:
        GLuint _VAO;

};

class BufferObject
{
    public:
        BufferObject(int Amount,int Type);
        void Bind();
        void PassData(GLfloat* Data,size_t Size,int Mode);
        void PassData(GLuint* Data,size_t Size,int Mode);
        void PassData(GLboolean* Data,size_t Size,int Mode);
        void Delete();
    
    private:
        int _Type;
        int _Amount;
        GLuint _BufferObj;
};

#endif BUFFERS_H