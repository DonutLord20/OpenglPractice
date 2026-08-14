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


class Game
{
    public:
        Game();
        virtual bool Initialize(int WindowWidth,int WindowHeight,const char* WindowTitle);
        void Run();
    protected:
        virtual void Update(float DeltaTime);
        virtual void Draw();
        virtual void  QuitGame();
        GLFWwindow* _Window;
        float _LastTime;
        

};
#endif 