#include <glad/glad.h>
#include <GLFW/glfw3.h>
#include <iostream>
#include <cmath>
#include "Game.hpp"

class TestGame : Game
{
    public : 
        TestGame() : Game() {}

        bool Initialize(int WindowWidth,int WindowHeight,const char* WindowTitle) override
        {
            return Game::Initialize(WindowWidth,WindowHeight,WindowTitle);
        }

        void Run()
        {
            Game::Run();
        }

    protected :
        void Update(float DeltaTime) override
        {
            
        }

        void Draw() override
        {

        }

        void QuitGame() override
        {
            Game::QuitGame();
        }
   
    
};




int main()
{
    TestGame* MyGame = new TestGame();
    MyGame->Initialize(1024,800,"trinagle");
    MyGame->Run();
    delete MyGame;
    return 0;
}

