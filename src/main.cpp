#include <glad/glad.h>
#include <GLFW/glfw3.h>
#include <iostream>
#include <cmath>
#include "GraphicsLibs/Game.hpp"
#include "GraphicsLibs/Camera.hpp"
#include "GraphicsLibs/Actors-Componants.hpp"
#include "Maze.hpp"

class TestGame : Game
{
    public : 
        TestGame() : Game() {}

        bool Initialize(int WindowWidth,int WindowHeight,const char* WindowTitle) override
        {
            bool Success = Game::Initialize(WindowWidth,WindowHeight,WindowTitle);
            _Graph = new Graph();
            _Camera = new Camera(glm::vec3(0.0f,0.0f,0.0f),-90.0f,0.0f,glm::vec3(0.0f,1.0f,0.0f),_ShaderProgram,10.0f,35.0f,45.0f,_Window);

          _Graph->AddNode(new GraphNode(glm::vec3(0.0f,0.0f,-3.0f)));
            
            

            for (int j = 0; j < _Graph->GetSize(); j++)
            {
                GraphNode* Temp = _Graph->GetGraphNode(j);
                _Actors.push_back((Actor*)new Wall(this,glm::vec3(Temp->GetPosition().x -0.5f,Temp->GetPosition().y,Temp->GetPosition().z),glm::vec3(0.0f,90.0f,0.0f),1.0f,1.0f,glm::vec3(1.0f,0.3f,0.1f),_ShaderProgram));
                _Actors.push_back((Actor*)new Wall(this,glm::vec3(Temp->GetPosition().x +0.5f,Temp->GetPosition().y,Temp->GetPosition().z),glm::vec3(0.0f,90.0f,0.0f),1.0f,1.0f,glm::vec3(1.0f,0.3f,0.1f),_ShaderProgram));
                _Actors.push_back((Actor*)new Wall(this,glm::vec3(Temp->GetPosition().x,Temp->GetPosition().y,Temp->GetPosition().z -0.5f),glm::vec3(0.0f,0.0f,0.0f),1.0f,1.0f,glm::vec3(1.0f,0.3f,0.1f),_ShaderProgram));
                _Actors.push_back((Actor*)new Wall(this,glm::vec3(Temp->GetPosition().x,Temp->GetPosition().y,Temp->GetPosition().z + 0.5f),glm::vec3(0.0f,0.0f,0.0f),1.0f,1.0f,glm::vec3(1.0f,0.3f,0.1f),_ShaderProgram));
            }
            
            return Success;
        }

        void Run()
        {
            Game::Run();
        }

    protected :
        Graph* _Graph;
        Camera* _Camera;
    
        void Update(float DeltaTime) override
        {
            _Camera->Update(DeltaTime);
        }

        void Draw() override
        {
           for (int i = 0; i < _Actors.size(); i++)
           {
                _Actors[i]->Draw();
           }
        }

        void QuitGame() override
        {
           delete _Camera;
           delete _Graph;
           
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

