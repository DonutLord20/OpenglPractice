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
int main()
{
   glfwInit();

   glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR,3);
   glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR,3);
   glfwWindowHint(GLFW_OPENGL_PROFILE,GLFW_OPENGL_CORE_PROFILE);

   GLFWwindow* window = glfwCreateWindow(1024,800,"Trinagle",NULL,NULL);

   if (window == NULL)
   {
     std::cout << "Failed to create window";
     glfwTerminate();
     return -1;
   }
   glfwMakeContextCurrent(window);
   
   
   gladLoadGL();
   glViewport(0,0,1024,800);
   glEnable(GL_DEPTH_TEST);
   //end of intialization

   const char* VertexShaderSource = "#version 330 core\n"
   "layout (location = 0) in vec3 aPos;\n"
   "uniform mat4 model;\n"
   "uniform mat4 view;\n"
   "uniform mat4 projection;\n"
   "void main()\n"
   "{\n"
   "gl_Position = projection * view * model * vec4(aPos.x,aPos.y,aPos.z,1.0);"
   "}\0";

   const char* FragmentShaderSource = "#version 330 core\n"
   "out vec4 FragColor;\n"
   "void main()\n"
   "{\n"
   "FragColor = vec4(0.8,0.3,0.02,1.0);\n"
   "}\0";


  GLfloat Vertices[] = 
   {
     0.0f,0.5f,0.0f,
     -0.5f,-0.5f,-0.5f,
     0.5f,-0.5f,-0.5f,
     -0.5f,-0.5f,0.5f,
     0.5f,-0.5f,0.5f
   };

   GLuint Indeces[] = 
   {
      0,1,2,
      0,1,3,
      0,3,4,
      0,4,2
   };

   GLint ShaderProgram = glCreateProgram();
   Shader* VertexShader = new Shader(VertexShaderSource,ShaderProgram,GL_VERTEX_SHADER);
   Shader* FragmentShader = new Shader(FragmentShaderSource,ShaderProgram,GL_FRAGMENT_SHADER);
   VertexShader->Activate();
   FragmentShader->Activate();
   glLinkProgram(ShaderProgram);
   VertexShader->Delete();
   FragmentShader->Delete();

   VertexArrayObject* VAO = new VertexArrayObject();
   BufferObject* VBO = new BufferObject(1,GL_ARRAY_BUFFER);
   BufferObject* EBO = new BufferObject(1,GL_ELEMENT_ARRAY_BUFFER);

   VAO->Bind();
   VBO->Bind();
   VBO->PassData(Vertices,sizeof(Vertices),GL_STATIC_DRAW);
   VAO->CreateAttribePointer(0,3,GL_FLOAT,GL_FALSE,sizeof(GLfloat) * 3,(void*)(0));
   EBO->Bind();
   EBO->PassData(Indeces,sizeof(Indeces),GL_STATIC_DRAW);
   VAO->UnBind();


   float LastTime = glfwGetTime();
   glm::vec3 Camerapos = glm::vec3(0.0f,0.0f,-3.0f);
   glm::vec3 Front = glm::vec3(0.0f,0.0f,0.0f);
   float Yaw = 90.0f;
   float Pitch = 0.0f;
   while(!glfwWindowShouldClose(window))
   {
      glfwPollEvents();
      glClearColor(0.1f, 0.1f, 0.1f, 1.0f);
      glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
      float CurrenTime = glfwGetTime();
      float DeltaTime = CurrenTime - LastTime;
      LastTime = CurrenTime;

      glUseProgram(ShaderProgram);

      int AState = glfwGetKey(window,GLFW_KEY_A);
      int DState = glfwGetKey(window,GLFW_KEY_D);
      int WState = glfwGetKey(window,GLFW_KEY_W);
      int SState = glfwGetKey(window,GLFW_KEY_S);
      int LeftState = glfwGetKey(window,GLFW_KEY_LEFT);
      int RightState = glfwGetKey(window,GLFW_KEY_RIGHT);
      if (AState == GLFW_PRESS)
      {
         Camerapos -= glm::normalize(glm::cross(Front,glm::vec3(0,1,0))) * DeltaTime * 10.0f;
      }
      if (DState == GLFW_PRESS)
      {
         Camerapos += glm::normalize(glm::cross(Front,glm::vec3(0,1,0))) * DeltaTime * 10.0f;
      }
      if (WState == GLFW_PRESS)
      {
         Camerapos += DeltaTime * 10.0f * Front;
      }
      if (SState == GLFW_PRESS)
      {
         Camerapos -= DeltaTime * 10.0f * Front;
      }
      if (LeftState == GLFW_PRESS)
      {
         Yaw -= 90.0f * DeltaTime;
      }
      if (RightState == GLFW_PRESS)
      {
        Yaw += 90.0f * DeltaTime;
      }

      Front.x = cos(glm::radians(Yaw)) * cos(glm::radians(Pitch));
      Front.y = sin(glm::radians(Pitch));
      Front.z = sin(glm::radians(Yaw)) * cos(glm::radians(Pitch));

      Front = glm::normalize(Front);

      glm::mat4 model = glm::rotate(glm::mat4(1.0f),glm::radians(0.0f),glm::vec3(0.0f,1.0f,0.0f));
      GLuint modelloc = glGetUniformLocation(ShaderProgram,"model");
      glUniformMatrix4fv(modelloc,1,GL_FALSE,glm::value_ptr(model));


      glm::mat4 view = glm::lookAt(Camerapos,Camerapos + Front,glm::vec3(0.0f,1.0f,0.0f));
      GLuint viewloc = glGetUniformLocation(ShaderProgram,"view");
      glUniformMatrix4fv(viewloc,1,GL_FALSE,glm::value_ptr(view));

      glm::mat4 projection = glm::perspective(glm::radians(45.0f),1024.0f / 800.0f,1.0f,100.0f);
      GLuint projectionloc = glGetUniformLocation(ShaderProgram,"projection");
      glUniformMatrix4fv(projectionloc,1,GL_FALSE,glm::value_ptr(projection));

      VAO->Bind();
      glDrawElements(GL_TRIANGLES,sizeof(Indeces) / sizeof(GLuint),GL_UNSIGNED_INT,0);
      glfwSwapBuffers(window);
   }
   
   VBO->Delete();
   EBO->Delete();
   VAO->Delete();
   delete VBO;
   delete EBO;
   delete VAO;
   delete VertexShader;
   delete FragmentShader;
   glDeleteProgram(ShaderProgram);
   glfwDestroyWindow(window);
   glfwTerminate();
   return 0;
}