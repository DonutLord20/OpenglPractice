#include <glm/vec3.hpp> 
#include <glm/vec4.hpp> 
#include <glm/mat4x4.hpp> 
#include <glm/ext/matrix_transform.hpp> 
#include <glm/ext/matrix_clip_space.hpp> 
#include <glm/ext/scalar_constants.hpp> 
#include <glm/gtc/type_ptr.hpp>
#include <cmath>
#include "GraphicsLibs/Game.hpp"
#include "GraphicsLibs/Camera.hpp"
#include "GraphicsLibs/Actors-Componants.hpp"
#include <map>
#include "Maze.hpp"

Wall::Wall(Game* Owner,glm::vec3 Position,glm::vec3 Rotation,float Width,float Height,glm::vec3 Colour,GLuint ShaderProgram) : Actor(Owner)
{
    _Position = Position;
    _Rotation = Rotation;
    _Width = Width;
    _Height = Height;
    _Colour = Colour;
    _ShaderProgram = ShaderProgram;



    GLfloat Vertices[] =
    {
        (_Width / 2.0f) * -1.0f,_Height / 2.0f,0.0f,Colour.x,Colour.y,Colour.z,
        _Width / 2.0f,_Height / 2.0f,0.0f,Colour.x,Colour.y,Colour.z,
        (_Width / 2.0f) * -1.0f,(_Height / 2.0f) * -1.0f,0.0f,Colour.x,Colour.y,Colour.z,
        (_Width / 2.0f) * -1.0f,(_Height / 2.0f) * -1.0f,0.0f,Colour.x,Colour.y,Colour.z,
        _Width / 2.0f,(_Height / 2.0f) * -1.0f,0.0f,Colour.x,Colour.y,Colour.z,
        _Width / 2.0f,_Height / 2.0f,0.0f,Colour.x,Colour.y,Colour.z
    };
    
    for (int i = 0; i < sizeof(Vertices) / sizeof(GLfloat); i++)
    {
        _Vertices[i] = Vertices[i];
    }
    

    _Mesh = new Mesh(_Vertices,sizeof(_Vertices) / sizeof(GLfloat),_Position);
    _Mesh->Load(_ShaderProgram);
    _Mesh->IncRotation(_Rotation);
}

void Wall::Draw()
{
    _Mesh->Draw(_ShaderProgram);
}

Graph::Graph() {}

GraphNode::GraphNode(glm::vec3 Position)
{
    _Position = Position;
}

void GraphNode::AddNeighbour(GraphNode* Neighbour,int Cost)
{
    _Neighbours.push_back(Neighbour);
    _Costs[Neighbour] = Cost;
}