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
            _Pyramid = new Pyramid(this,glm::vec3(0.0f,0.0f,-3.0f),_ShaderProgram);
            _Pyramid2 = new Pyramid(this,glm::vec3(0.0f,0.0f,6.0f),_ShaderProgram);

            _Pyramid2->Load();
            _Pyramid->Load();
            
            _Actors.push_back((Actor*)_Player);
            _Actors.push_back((Actor*)_Pyramid);
            return Success;
        }

        void Run()
        {
            Game::Run();
        }

    protected :
       User* _Player;
       Pyramid* _Pyramid;
       Pyramid* _Pyramid2;
    
        void Update(float DeltaTime) override
        {
          _Player->Update(DeltaTime);
          _Pyramid->Update(DeltaTime);
          _Pyramid2->Update(DeltaTime);
        }

        void Draw() override
        {
           _Pyramid->Draw();
           _Pyramid2->Draw();
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

