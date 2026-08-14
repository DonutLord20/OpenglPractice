#ifndef ACTORS_COMPONANTS_H
#define ACTORS_COMPONANTS_H

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

class Texture
{
    public:
        Texture(const char* FileName);
        void Load(int DesiredChannels);
        void UnLoad();
        void Activate(int Unit,GLint SamplerLoc);
        GLuint GetReference();
    private:
        GLuint _Reference;
        const char* _FileName;
};


class Mesh
{
    public:
        Mesh(GLfloat Vertices[],glm::vec3 Position);
        virtual void Load(GLuint ShaderProgram);
        virtual void UnLoad();
        virtual void Draw(GLuint ShaderProgram);
    protected:
        GLfloat* _Vertices;
        glm::vec3 _Position;
        VertexArrayObject* _VAO;
        BufferObject* _VBO;

};


#endif
