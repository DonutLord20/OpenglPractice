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
#include "Game.hpp"

Game::Game()
{
    _Window = nullptr;
    _LastTime = glfwGetTime();
}

bool Game::Initialize(int WindowWidth,int WindowHeight,const char* WindowTitle)
{
    if (!glfwInit())
    {
        std::cerr << "Could not initialize glfw";
        return false;
    }
    glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR,3);
    glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR,3);
    glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);


    _Window = glfwCreateWindow(WindowWidth,WindowHeight,WindowTitle,NULL,NULL);

    if (!_Window)
    {
        std::cerr << "Failed to create Window";
        glfwTerminate();
        return false;
    }

    glfwMakeContextCurrent(_Window);
    gladLoadGL();
    return true;
}


void Game::Run()
{
    while(!glfwWindowShouldClose(_Window))
    {
        glClearColor(0.0f,0.0f,0.0f,1.0f);
        glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
        glfwPollEvents();
        float CurrentTime = glfwGetTime();
        float DeltaTime = CurrentTime - _LastTime;
        _LastTime = CurrentTime;
        Update(DeltaTime);
        Draw();
        glfwSwapBuffers(_Window);
    }

    QuitGame();
}

void Game::Update(float DeltaTime)
{

}

void Game::Draw()
{

}

void Game::QuitGame()
{
    glfwDestroyWindow(_Window);
    glfwTerminate();
}