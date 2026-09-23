#ifndef MAZE_H
#define MAZE_H

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
#include "GraphicsLibs/Actors-Componants.hpp"
#include <map>

class Wall : Actor
{
    public:
        Wall(Game* Owner,glm::vec3 Position,glm::vec3 Rotation,float Width,float height,glm::vec3 Colour,GLuint ShaderProgram);
        void Draw() override;
    
    private:
        glm::vec3 _Position;
        glm::vec3 _Rotation;
        float _Width;
        float _Height;
        glm::vec3 _Colour;
        GLuint _ShaderProgram;
        Mesh* _Mesh;

        GLfloat _Vertices[36];
    
};

class GraphNode
{
    public:
        GraphNode(glm::vec3 Position);
        void AddNeighbour(GraphNode* Neighbour,int Cost);
        glm::vec3 GetPosition() {return _Position;};
        std::vector<GraphNode*> GetNeighbours() {return _Neighbours;};
    private:
        glm::vec3 _Position;
        std::vector<GraphNode*> _Neighbours;
        std::map<GraphNode*,int> _Costs;
};

class Graph
{
    public:
        Graph();
        void AddNode(GraphNode* Node) {_Nodes.push_back(Node);};
        int GetSize() {return _Nodes.size();};
        GraphNode* GetGraphNode(int Index) {return _Nodes[Index];};
    private:
        std::vector<GraphNode*> _Nodes;
        
};

#endif