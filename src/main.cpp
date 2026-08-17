#include <glad/glad.h>
#include <GLFW/glfw3.h>
#include <iostream>
#include <cmath>
#include "Game.hpp"
#include "Camera.hpp"
#include "Actors-Componants.hpp"

class TestGame : Game
{
    public : 
        TestGame() : Game() {}

        bool Initialize(int WindowWidth,int WindowHeight,const char* WindowTitle) override
        {
            bool Success = Game::Initialize(WindowWidth,WindowHeight,WindowTitle);
            
            _Camera = new Camera(glm::vec3(0.0f,0.0f,0.0f),glm::vec3(0.0f,0.0f,1.0f),glm::vec3(0.0f,1.0f,0.0f),_ShaderProgram,10.0f,45.0f,45.0f,_Window);

            GLfloat _PyramidVertices[] = {
                -0.5f,-0.5f,-0.5f,   0.2f,0.3f,0.4f,
                0.5f,-0.5f,-0.5f,    0.2f,0.3f,0.4f,
                0.0f,0.5f,0.0f,      0.2f,0.3f,0.4f,

                -0.5f,-0.5f,0.5f,    0.2f,0.3f,0.4f,
                -0.5f,-0.5f,-0.5f,   0.2f,0.3f,0.4f,
                0.0f,0.5f,0.0f,     0.2f,0.3f,0.4f,

                -0.5f,-0.5f,0.5f,    0.2f,0.3f,0.4f,
                0.5f,-0.5f,0.5f,     0.2f,0.3f,0.4f,
                0.0f,0.5f,0.0f,      0.2f,0.3f,0.4f,

                0.5f,-0.5f,0.5f,     0.2f,0.3f,0.4f,
                0.5f,-0.5f,-0.5f,    0.2f,0.3f,0.4f,
                0.0f,0.5f,0.0f,      0.2f,0.3f,0.4f

            };

            _Pyramid = new Mesh(_PyramidVertices,sizeof(_PyramidVertices) / sizeof(GLfloat),glm::vec3(0.0f,0.0f,3.0f));
            _Pyramid->Load(_ShaderProgram);
            
            return Success;
        }

        void Run()
        {
            Game::Run();
        }

    protected :
        Camera* _Camera;
        Mesh* _Pyramid;
    
        void Update(float DeltaTime) override
        {
            _Camera->Update(DeltaTime);
        }

        void Draw() override
        {
            _Pyramid->Draw(_ShaderProgram);
        }

        void QuitGame() override
        {
           
            _Pyramid->UnLoad();
            
            delete _Pyramid;
            delete _Camera;

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

