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
#include "Camera.hpp"

Camera::Camera(glm::vec3 Position,glm::vec3 direction,glm::vec3 Up,GLint ShaderProgram,float MoveSpeed,float RotateSpeed,GLFWwindow* Window)
{
    _Position = Position;
    _Direction = direction;
    _Up = Up;
    _ShaderProgram = ShaderProgram;
    _MoveSpeed = MoveSpeed;
    _RotateSpeed = RotateSpeed;
    _Window = Window;
    _Yaw = 90.0f;
    _Pitch = 0.0f;
    glfwGetCursorPos(_Window,&_LastCursorX,&_LastCursorY);
    
}

void Camera::Update(float DeltaTime)
{
    double CurrentCursorX;
    double CurrentCursorY;
    glfwGetCursorPos(_Window,&CurrentCursorX,&CurrentCursorY);

    if (glfwGetKey(_Window,GLFW_KEY_W) == GLFW_PRESS)
    {
        _Position += _MoveSpeed * DeltaTime * _Direction;
    }
    if (glfwGetKey(_Window,GLFW_KEY_S) == GLFW_PRESS)
    {
        _Position -= _MoveSpeed * DeltaTime * _Direction;
    }
    if (glfwGetKey(_Window,GLFW_KEY_A))
    {
        _Position += _MoveSpeed * DeltaTime * glm::normalize(glm::cross(_Position,_Up));
    }
    if (glfwGetKey(_Window,GLFW_KEY_D))
    {
        _Position -= _MoveSpeed * DeltaTime * glm::normalize(glm::cross(_Position,_Up));
    }

    if (_Position.y > 0 || _Position.y < 0)
    {
        _Position.y = 0;
    }

    _Yaw -= (_LastCursorX - CurrentCursorX) * _RotateSpeed * DeltaTime;
    _Pitch += (_LastCursorY - CurrentCursorY) * _RotateSpeed * DeltaTime;

    _LastCursorX = CurrentCursorX;
    _LastCursorY = CurrentCursorY;

    _Direction.x = cos(glm::radians(_Yaw)) * cos(glm::radians(_Pitch));
    _Direction.y = sin(glm::radians(_Pitch));
    _Direction.z = sin(glm::radians(_Yaw)) * cos(glm::radians(_Pitch));

    glm::normalize(_Direction);

    _ViewMat = glm::lookAt(_Position,_Position + _Direction,_Up);

    GLint Viewloc = glGetUniformLocation(_ShaderProgram,"view");
    glUniformMatrix4fv(Viewloc,1,GL_FALSE,glm::value_ptr(_ViewMat));
}