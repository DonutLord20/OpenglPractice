#include <glad/glad.h>
#include <GLFW/glfw3.h>
#include <iostream>
#include <cmath>
#include "Game.hpp"
#include "Camera.hpp"
#include "Actors-Componants.hpp"
#include "TestingMyClasses.hpp"

class TestGame : Game
{
    public : 
        TestGame() : Game() {}

        bool Initialize(int WindowWidth,int WindowHeight,const char* WindowTitle) override
        {
            bool Success = Game::Initialize(WindowWidth,WindowHeight,WindowTitle);
            
            GLfloat Vertices[] =
            {
                0.0f,  0.5f,  0.0f,    0.0f,1.0f,0.0f,      
                -0.5f, -0.5f, -0.5f,   0.0f,1.0f,0.0f,   
                0.5f, -0.5f, -0.5f,    0.0f,1.0f,0.0f,   

    
                0.0f,  0.5f,  0.0f,      0.0f,1.0f,0.0f,    
                -0.5f, -0.5f,  0.5f,     0.0f,1.0f,0.0f, 
                -0.5f, -0.5f, -0.5f,     0.0f,1.0f,0.0f, 

    
                0.0f,  0.5f,  0.0f,      0.0f,1.0f,0.0f, 
                0.5f, -0.5f, -0.5f,      0.0f,1.0f,0.0f, 
                0.5f, -0.5f,  0.5f,      0.0f,1.0f,0.0f, 

    
                0.0f,  0.5f,  0.0f,      0.0f,1.0f,0.0f, 
                0.5f, -0.5f,  0.5f,      0.0f,1.0f,0.0f, 
                -0.5f, -0.5f,  0.5f,     0.0f,1.0f,0.0f, 
            };
            _Pyramid = new Mesh(Vertices,sizeof(Vertices) / sizeof(GLfloat),glm::vec3(0.0f,0.0f,3.0f));
            _Pyramid->Load(_ShaderProgram);
            _Pyramid2 = new Mesh(Vertices,sizeof(Vertices) / sizeof(GLfloat),glm::vec3(5.0f,0.0f,-6.0f));
            _Pyramid2->Load(_ShaderProgram);
            _Player = new Camera(glm::vec3(0.0f,0.0f,0.0f),glm::vec3(0.0f,0.0f,1.0f),glm::vec3(0.0f,1.0f,0.0f),_ShaderProgram,10.0f,45.0f,45.0f,_Window);
            
            
            return Success;
        }

        void Run()
        {
            Game::Run();
        }

    protected :
       Mesh* _Pyramid;
       Mesh* _Pyramid2;
       Camera* _Player;
    
        void Update(float DeltaTime) override
        {
          _Player->Update(DeltaTime);
        }

        void Draw() override
        {
           _Pyramid->Draw(_ShaderProgram);
           _Pyramid2->Draw(_ShaderProgram);
        }

        void QuitGame() override
        {
           
           _Pyramid->UnLoad();

           delete _Pyramid;
           delete _Player;
           
            Game::QuitGame();
        }
   
    
};




int main()
{
    TestGame* MyGame = new TestGame();
    if (!MyGame->Initialize(1024,800,"trinagle"))
    {
        return - 1;
    }
    MyGame->Run();
    delete MyGame;
    return 0;
}

