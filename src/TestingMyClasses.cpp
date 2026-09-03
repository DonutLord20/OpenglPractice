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

    _Mesh = new Mesh(_Vertices,sizeof(_Vertices) / sizeof(GLfloat),Position);
    _ShaderProgram = ShaderProgram;
    _PhysicsComponant = new PhysicsComponant(this,15.0f,0.5f,glm::vec3(0.0f));
    
    
}

void Pyramid::Load()
{
    _Mesh->Load(_ShaderProgram);
}

void Pyramid::UnLoad()
{
    _Mesh->UnLoad();
}

void Pyramid::Update(float DeltaTime)
{
    Force Friction;
    Friction.Componants = glm::vec3(0.0f,0.0f,75.0f);

    
    if (_PhysicsComponant->GetVelocity().z < 0)
    {
        _PhysicsComponant->AddActingForce(Friction);
    }
    _PhysicsComponant->Update(_Owner->GetActors(),DeltaTime);
    _Mesh->IncPosition(_PhysicsComponant->GetVelocity() * DeltaTime);

    
   
    
}

void Pyramid::Draw()
{
    _Mesh->Draw(_ShaderProgram);
}



User::User(Game* Owner,glm::vec3 Position,GLuint ShaderProgram, GLFWwindow* Window) : Actor(Owner)
{
    _ShaderProgram = ShaderProgram;
    _Camera = new Camera(Position,-90.0f,0.0f,glm::vec3(0.0f,1.0f,0.0f),_ShaderProgram,10.0f,45.0f,45.0f,Window);
    _PhysicsComponant = new PhysicsComponant(this,60.0f,0.5f,glm::vec3(0.0f));
}


void User::Update(float DeltaTime)
{
    Force Push;
    Push.Componants = glm::vec3(0.0f,0.0f,-100.0f);
    _PhysicsComponant->AddActingForce(Push);
    _Camera->Update(DeltaTime);
    _PhysicsComponant->Update(_Owner->GetActors(),DeltaTime);
    
}

