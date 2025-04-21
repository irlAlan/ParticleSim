#include <cmath>
#include <cstdlib>

#define GLFW_INCLUDE_NONE
#include <GLFW/glfw3.h>
#include <glad/glad.h>

#include <fmt/core.h>
#include <Eigen/Dense>
#include <imgui.h>

#include <ParticleSim/Shaders.h>

int processInput(GLFWwindow* window, int &key);
void framebuffer_size_callback(GLFWwindow *window, int width, int height);
void Exit(std::string message, int exit_code);

struct WinConf{
  const std::string title = "First";
  Eigen::RowVector2i dim = {900, 800};
}winConf;


int main() {
  if(glfwInit() == GLFW_FALSE){
    Exit("Failed to initialise GLFW", -1);
  }
  glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3);
  glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 3);
  glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);
  
  #if defined(__APPLE__)
    glfwWindowHint(GLFW_OPENGL_FORWARD_COMPAT, GL_TRUE);
  #endif

// put this in a test
  GLFWwindow *win = glfwCreateWindow(winConf.dim.x(), winConf.dim.y(), winConf.title.c_str(), nullptr, nullptr);
  if(win == nullptr){
    Exit("Failed to create GLFW window", -1);

  }
  glfwMakeContextCurrent(win);
  if(!gladLoadGLLoader((GLADloadproc)glfwGetProcAddress)){
    Exit("Failed to initialise glad", -1);
  }

  glViewport(0, 0,winConf.dim.x(), winConf.dim.y());
  glfwSetFramebufferSizeCallback(win, framebuffer_size_callback);


  // Drawing a Triangle to the screen
  // Requires a Fragment shader which is all the date needed to render
  // a singel pixel 

  Shaders shader{"../shaders/vShader.vertex", "../shaders/fShader.fragment"};


  float verticies[] = { // colours
    0.5f, -0.5f, 0.0f, 1.0f, 0.0f, 0.0f,//bottom right
   -0.5f, -0.5f, 0.0f, 0.0f, 1.0f, 0.0f,// bottom left
    0.0f,  0.5f, 0.0f, 0.0f, 0.0f, 1.0f //top
  };


 // unsigned int indicies[] = {
 //   0, 1, 3, // first triangle
 //   1, 2, 3 // second triangle
 // };

  unsigned int VBO, VAO;
  glGenBuffers(1, &VBO);
  glGenVertexArrays(1, &VAO);

  glBindBuffer(GL_ARRAY_BUFFER, VBO);
  glBindVertexArray(VAO);

  glBufferData(GL_ARRAY_BUFFER, sizeof(verticies), verticies, GL_DYNAMIC_DRAW);


  //unsigned int EBO;
  //glGenBuffers(1, &EBO);
  //glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, EBO);
  //glBufferData(GL_ELEMENT_ARRAY_BUFFER, sizeof(indicies), indicies, GL_DYNAMIC_DRAW);


  // position attribute
  glVertexAttribPointer(0,3, GL_FLOAT, GL_FALSE, 6*sizeof(float), (void*)0);
  glEnableVertexAttribArray(0);

  // colour attribute
  glVertexAttribPointer(1, 3, GL_FLOAT, GL_FALSE, 6*sizeof(float), (void*)(3*sizeof(float)));
  glEnableVertexAttribArray(1);

  glBindBuffer(GL_ARRAY_BUFFER, 0);
  glBindVertexArray(0);

  int key;

  while(!glfwWindowShouldClose(win)){
    processInput(win, key);

    glClearColor(0.2f, 0.3f,0.3f,1.0f);
    glClear(GL_COLOR_BUFFER_BIT);

    glfwPollEvents();


    shader.useShaderProgram();
    //glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, EBO);
    if(key == 1){
      glPolygonMode(GL_FRONT_AND_BACK, GL_LINE);
    }
    // glDrawElements(GL_TRIANGLES, 6, GL_UNSIGNED_INT, 0);
    glDrawArrays(GL_TRIANGLES, 0, 3);
    glBindVertexArray(0);

    glBindVertexArray(VAO);

    glfwSwapBuffers(win);
  }

  Exit("Finished and Closing Window", 0);
}

void framebuffer_size_callback(GLFWwindow *window, int width, int height){
  glViewport(0,0, width, height);
}

int processInput(GLFWwindow* window, int &key){
  if(glfwGetKey(window, GLFW_KEY_W) == GLFW_PRESS){
    key = 1;
  }
  if(glfwGetKey(window, GLFW_KEY_ESCAPE)){
    glfwSetWindowShouldClose(window, true);
  }
  return key;
}

void Exit(std::string message, int exit_code){
  glfwTerminate();
  fmt::println("Message: {}\nExit code: {}", message, exit_code);
  exit(exit_code);
}

