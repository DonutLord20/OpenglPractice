#ifndef GAME_H
#define GAME_H


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
#include "Actors-Componants.hpp"
#include <vector>

class Game;
class Actor;

class Game
{
    public:
        Game();
        virtual bool Initialize(int WindowWidth,int WindowHeight,const char* WindowTitle);
        std::vector<Actor*> GetActors() {return _Actors;};
        void Run();
    protected:
        virtual void Update(float DeltaTime);
        virtual void Draw();
        virtual void  QuitGame();
        GLFWwindow* _Window;
        float _LastTime;
        GLuint _ShaderProgram;
        std::vector<Actor*> _Actors;

        

};

class Actor
{
    public:
        Actor(Game* Owner);
        virtual void Update(float DelatTime);
        virtual Mesh* GetMesh() {return nullptr;};
        virtual Camera* GetCamera() {return nullptr;};
        virtual void Load();
        virtual void UnLoad();
        virtual void Draw();
    protected:
        Game* _Owner;
};

#endif 