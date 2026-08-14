
#include <glad/glad.h>
#include <GLFW/glfw3.h>
#include <iostream>
#include <cmath>
#include "Shaders.hpp"
#include "Buffers.hpp"
#include <glm/vec3.hpp> 
#include <glm/vec4.hpp> 
#include <glm/mat4x4.hpp> 
#include <glm/ext/matrix_transform.hpp> 
#include <glm/ext/matrix_clip_space.hpp> 
#include <glm/ext/scalar_constants.hpp> 
#include <glm/gtc/type_ptr.hpp>
#include "Camera.hpp"
#include "stb/stb_image.h"
#include "Actors-Componants.hpp"

Texture::Texture(const char* FileName)
{
    _FileName = FileName;
}

void Texture::Load(int DesiredChannels)
{
    int Width;
    int Height;
    int Channels;
    unsigned char* Texture = stbi_load(_FileName,&Width,&Height,&Channels,DesiredChannels);

    if (!Texture)
    {
        std::cerr << "Failed to Load texture";
        return;
    }
    glGenTextures(1,&_Reference);
    glBindTexture(GL_TEXTURE_2D,_Reference);
    
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_CLAMP_TO_EDGE);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_CLAMP_TO_EDGE);

    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR_MIPMAP_LINEAR); 
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR); 
    


    if (DesiredChannels == 4)
    {
        glTexImage2D(GL_TEXTURE_2D,0,GL_RGBA,Width,Height,0,GL_RGBA,GL_UNSIGNED_BYTE,Texture);
    }
    else
    {
        glTexImage2D(GL_TEXTURE_2D,0,GL_RGB,Width,Height,0,GL_RGB,GL_UNSIGNED_BYTE,Texture);
    }

    glGenerateMipmap(GL_TEXTURE_2D);
    stbi_image_free(Texture);
    glBindTexture(GL_TEXTURE_2D,0);
}

void Texture::UnLoad()
{
    glDeleteTextures(1,&_Reference);
}

void Texture::Activate(int Unit,GLint SamplerLoc)
{
    glActiveTexture(GL_TEXTURE0 + Unit);
    glBindTexture(GL_TEXTURE_2D,_Reference);
    glUniform1i(SamplerLoc,Unit);
    

}


Mesh::Mesh(GLfloat Vertices[],glm::vec3 Position)
{
    _Vertices = Vertices;
    _Position = Position;
    _VAO = nullptr;
    _VBO = nullptr;
   
}

void Mesh::Load(GLuint ShaderProgram)
{
    _VAO = new VertexArrayObject();
    _VBO = new BufferObject(1,GL_ARRAY_BUFFER);
  

    _VAO->Bind();
    _VAO->CreateAttribePointer(0,3,GL_FLOAT,GL_FALSE,sizeof(GLfloat) * 6,(void*)(0));
    _VAO->CreateAttribePointer(1,3,GL_FLOAT,GL_FALSE,sizeof(GLfloat) * 6,(void*)(sizeof(GLfloat) * 3));

    _VBO->Bind();
    _VBO->PassData(_Vertices,sizeof(_Vertices),GL_STATIC_DRAW);

    _VAO->UnBind();

    glm::mat4 Transform = glm::mat4(1.0f);
    Transform = glm::translate(Transform,_Position);
    GLint TransformLoc = glGetUniformLocation(ShaderProgram,"Transform");
    glUniformMatrix4fv(TransformLoc,sizeof(Transform),GL_FALSE,glm::value_ptr(Transform));
}

