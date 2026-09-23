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
class PhysicsComponant;
struct Force;
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
        virtual PhysicsComponant* GetPhysicsComponant() {return nullptr;};
        virtual glm::vec3 GetPosition() {return glm::vec3(0.0f);};
        virtual glm::vec3 GetDirection() {return glm::vec3(0.0f);};
        virtual void Load();
        virtual void UnLoad();
        virtual void Draw();
    protected:
        Game* _Owner;
};


struct Force
{
    glm::vec3 Componants = glm::vec3(0.0f);
};

class PhysicsComponant
{
    public:
        PhysicsComponant(Actor* Owner,float Mass,float CollisionRadius,glm::vec3 StartVelocity);
        void Update(std::vector<Actor*> ToCheckForCollsions,float DelatTime);
        void SetVelocity(glm::vec3 Velocity) {_Velocity = Velocity;};
        Force GetResultantForce() {return _ResultantForce;}
        void AddActingForce(Force force) {_ActingForces.push_back(force);};
        glm::vec3 GetVelocity() {return _Velocity;};
        glm::vec3 GetAcceleration() {return _Acceleration;};
        float GetMass() {return _Mass;};
        glm::vec3 GetMomentum() {return _Momentum;};
    private:
        void CalculateResultantForce();
        Actor* _Owner;
        float _Mass;
        float _CollisionRadius;
        glm::vec3 _Momentum;
        glm::vec3 _Acceleration;
        glm::vec3 _Velocity;
        std::vector<Force> _ActingForces; 
        Force _ResultantForce;
        float _StartTime;
};

#endif 