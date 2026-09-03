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

#ifndef CAMERA_H
#define CAMERA_H

class Camera
{
    public:
        Camera(glm::vec3 Position,float StartYaw,float StartPitch,glm::vec3 Up,GLint ShaderProgram,float MoveSpeed,float RotateSpeed,float FOV,GLFWwindow* Window);
        void Update(float DeltaTime);
        glm::vec3 GetPosition() {return _Position;};
        glm::vec3 GetDirection() {return _Direction;}
        void SetMoveSpeed(float Speed) {_MoveSpeed = Speed;};
    private:
        glm::vec3 _Position;
        glm::vec3 _Direction;
        glm::vec3 _Up;
        GLint _ShaderProgram;
        glm::mat4 _ViewMat;
        glm::mat4 _ProjMat;
        GLFWwindow* _Window;
        float _Yaw;
        float _Pitch;
        float _MoveSpeed;
        float _RotateSpeed;
        float _FOV;
        double _LastCursorX;
        double _LastCursorY;
};
#endif CAMERA_H