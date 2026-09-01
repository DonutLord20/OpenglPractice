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
            _Player = new User(this,glm::vec3(0.0f,0.0f,0.0f),_ShaderProgram,_Window);
            _Pyramid = new Pyramid(this,glm::vec3(0.0f,0.0f,3.0f),_ShaderProgram);
            
            _Pyramid->Load();
            
            return Success;
        }

        void Run()
        {
            Game::Run();
        }

    protected :
       User* _Player;
       Pyramid* _Pyramid;
    
        void Update(float DeltaTime) override
        {
          _Player->Update(DeltaTime);
        }

        void Draw() override
        {
           _Pyramid->Draw();
        }

        void QuitGame() override
        {
           
         

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

