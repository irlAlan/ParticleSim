#include <ParticleSim/ParticleSim.h>
/*
 * add opengl
 * Make a window that works
 * add eigen
 * */

// void framebuffer_size_callback(GLFWwindow *window, int width, int height);

int main(){
  ParticleSim ps;
  ps.Init("Learning Opengl", ParticleSim::Vec2d{800, 600});


//  glfwInit();
//  glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3);
//  glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 3);
//  glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);
//  
//  #if defined(__APPLE__)
//    glfwWindowHint(GLFW_OPENGL_FORWARD_COMPAT, GL_TRUE);
//  #endif
//
//  GLFWwindow* window{glfwCreateWindow(800, 600, "Learning OpenGL", NULL, NULL)};
//  if(window == NULL){
//    fmt::println("Failed to create GLFW window");
//    glfwTerminate();
//    return -1;
//  }
//  glfwMakeContextCurrent(window);
//
//  if(!gladLoadGLLoader((GLADloadproc)glfwGetProcAddress)){
//    fmt::println("Failed to initialise glad");
//  }
//  glViewport(0, 0, 800, 600);
//  glfwSetFramebufferSizeCallback(window, framebuffer_size_callback);
//
//  while(!glfwWindowShouldClose(window)){
//    glfwSwapBuffers(window);
//    glfwPollEvents();
//  }
//
//  glfwTerminate();
	return 0;
}

//void framebuffer_size_callback(GLFWwindow *window, int width, int height){
//  glViewport(0, 0, width, height);
//}
