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
    _ShaderProgram = 0;
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
    glEnable(GL_DEPTH_TEST);
    glfwSetInputMode(_Window,GLFW_CURSOR,GLFW_CURSOR_DISABLED);

    const char* VertexShaderSource = "#version 330 core\n"
   "layout (location = 0) in vec3 aPos;\n"
   "layout (location = 1) in vec3 aColour;\n"
    "out vec3 Colour;\n"
   "uniform mat4 model;\n"
   "uniform mat4 view;\n"
   "uniform mat4 projection;\n"
   "void main()\n"
   "{\n"
   "gl_Position = projection * view * model * vec4(aPos,1.0);\n"
    "Colour = aColour;\n"
   "}\0";

   const char* FragmentShaderSource = "#version 330 core\n"
   "out vec4 FragColor;\n"
   "in vec3 Colour;\n"
   "void main()\n"
   "{\n"
   "FragColor = vec4(Colour,1.0);\n"
   "}\0";

   _ShaderProgram = glCreateProgram();
   Shader VertexShader = Shader(VertexShaderSource,_ShaderProgram,GL_VERTEX_SHADER);
   Shader FragmentShader = Shader(FragmentShaderSource,_ShaderProgram,GL_FRAGMENT_SHADER);

   VertexShader.Activate();
   FragmentShader.Activate();
   glLinkProgram(_ShaderProgram);
    
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