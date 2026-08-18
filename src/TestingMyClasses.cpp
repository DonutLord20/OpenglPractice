#include <glad/glad.h>
#include <GLFW/glfw3.h>
#include <iostream>
#include <cmath>
#include "Game.hpp"
#include "Camera.hpp"
#include "Actors-Componants.hpp"
#include "TestingMyClasses.hpp"

Pyramid::Pyramid(Game* Owner,glm::vec3 Position,GLuint ShaderProgram) : Actor(Owner)
{

    GLfloat _PyramidVertices[] = {
        
       -0.5f,-0.5f,-5.0f, 1.0f,1.0f,1.0f,
        0.5f,-0.5f,-5.0f, 0.0f,0.0f,0.0f,
        0.0f,0.5f,0.0f, 0.0f,0.0f,0.0f,

    };

    _Mesh = new Mesh(_PyramidVertices,sizeof(_PyramidVertices) / sizeof(GLfloat),Position);
    _ShaderProgram = ShaderProgram;


    
}

void Pyramid::Load()
{
    _Mesh->Load(_ShaderProgram);
}

void Pyramid::UnLoad()
{
    _Mesh->UnLoad();
}

void Pyramid::Draw()
{
    _Mesh->Draw(_ShaderProgram);
}



User::User(Game* Owner,glm::vec3 Position,GLuint ShaderProgram, GLFWwindow* Window) : Actor(Owner)
{
    _ShaderProgram = ShaderProgram;
    _Camera = new Camera(Position,glm::vec3(0.0f,0.0f,1.0f),glm::vec3(0.0f,1.0f,0.0f),_ShaderProgram,10.0f,45.0f,45.0f,Window);
}


void User::Update(float DeltaTime)
{
    _Camera->Update(DeltaTime);
}

