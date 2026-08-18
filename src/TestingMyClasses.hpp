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
        Mesh* GetMesh() override {return _Mesh;};
    private:
        Mesh* _Mesh;
        GLuint _ShaderProgram;

        
};

class User : Actor
{
    public:
        User(Game* Owner,glm::vec3 Position,GLuint ShaderProgram,GLFWwindow* Window);
        void Update(float DeltaTime) override;
        Camera* GetCamera() override {return _Camera;};
    private:
        Camera* _Camera;
        GLuint _ShaderProgram;
};

#endif