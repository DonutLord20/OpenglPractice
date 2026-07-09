#include <glad/glad.h>
#include <GLFW/glfw3.h>
#include <iostream>
#include <cmath>
#include "Shaders.hpp"

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
   //end of intialization

   const char* VertexShaderSource = "#version 330 core\n"
   "layout (location = 0) in vec3 aPos;\n"
   "void main()\n"
   "{\n"
   "gl_Position = vec4(aPos.x,aPos.y,aPos.z,1.0);"
   "}\0";

   const char* FragmentShaderSource = "#version 330 core\n"
   "out vec4 FragColor;\n"
   "void main()\n"
   "{\n"
   "FragColor = vec4(0.8,0.3,0.02,1.0);\n"
   "}\0";


  GLfloat Vertices[] = 
   {
     -0.5f,-0.5f,0.0f,
      -0.25f,0.0f,0.0f,
      0.0f,-0.5f,0.0f,
      0.5f,-0.5f,0.0f,
      0.25f,0.0f,0.0f,
      0.0f,0.5f,0.0f
   };

   GLuint Indeces[] = 
   {
      1,0,2,
      4,2,3,
      5,1,4
   };

   GLint ShaderProgram = glCreateProgram();
   Shader* VertexShader = new Shader(VertexShaderSource,ShaderProgram,GL_VERTEX_SHADER);
   Shader* FragmentShader = new Shader(FragmentShaderSource,ShaderProgram,GL_FRAGMENT_SHADER);
   VertexShader->Activate();
   FragmentShader->Activate();
   glLinkProgram(ShaderProgram);
   VertexShader->Delete();
   FragmentShader->Delete();

   GLuint VBO,VAO,EBO;

   glGenVertexArrays(1,&VAO);
   glBindVertexArray(VAO);

   glGenBuffers(1,&VBO);
   glBindBuffer(GL_ARRAY_BUFFER,VBO);
   glBufferData(GL_ARRAY_BUFFER,sizeof(Vertices),Vertices,GL_STATIC_DRAW);

   glGenBuffers(1,&EBO);
   glBindBuffer(GL_ELEMENT_ARRAY_BUFFER,EBO);
   glBufferData(GL_ELEMENT_ARRAY_BUFFER,sizeof(Indeces),Indeces,GL_STATIC_DRAW);

   glVertexAttribPointer(0,3,GL_FLOAT,GL_FALSE,sizeof(GLfloat) * 3,(void*)0);
   glEnableVertexAttribArray(0);
   glBindVertexArray(0);
   while(!glfwWindowShouldClose(window))
   {
      glfwPollEvents();
      glBindVertexArray(VAO);
      glUseProgram(ShaderProgram);
      glDrawElements(GL_TRIANGLES,9,GL_UNSIGNED_INT,0);
      glfwSwapBuffers(window);
   }
   
   delete VertexShader;
   delete FragmentShader;
   glDeleteProgram(ShaderProgram);
   glDeleteBuffers(1,&VBO);
   glDeleteBuffers(1,&EBO);
   glDeleteVertexArrays(1,&VAO);
   glfwDestroyWindow(window);
   glfwTerminate();
   return 0;
}