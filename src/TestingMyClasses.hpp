#ifndef TESTING_MY_CLASSES_H
#define TESTING_MY_CLASSES_H

#include <glad/glad.h>
#include <GLFW/glfw3.h>
#include <iostream>
#include <cmath>
#include "Game.hpp"
#include "Camera.hpp"
#include "Actors-Componants.hpp"


class Pyramid : Actor
{
    public:
        Pyramid(Game* Owner,glm::vec3 Position,GLuint ShaderProgram);
        void Load() override;
        void UnLoad() override;
        void Draw() override;
        void Update(float DeltaTime) override;
        Mesh* GetMesh() override {return _Mesh;};
        PhysicsComponant* GetPhysicsComponant() override {return _PhysicsComponant;}
        glm::vec3 GetPosition() override {return _Mesh->GetPosition();};
    private:
        Mesh* _Mesh;
        GLuint _ShaderProgram;
        PhysicsComponant* _PhysicsComponant;
        float _Rotate;
        GLfloat _Vertices[72] =
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

        
};

class User : Actor
{
    public:
        User(Game* Owner,glm::vec3 Position,GLuint ShaderProgram,GLFWwindow* Window);
        void Update(float DeltaTime) override;
        Camera* GetCamera() override {return _Camera;};
        PhysicsComponant* GetPhysicsComponant() override {return _PhysicsComponant;}
        glm::vec3 GetPosition() override {return _Camera->GetPosition();};
    private:
        Camera* _Camera;
        PhysicsComponant* _PhysicsComponant;
        GLuint _ShaderProgram;
};

#endif