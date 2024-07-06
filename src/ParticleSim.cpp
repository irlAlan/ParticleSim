#include <ParticleSim/ParticleSim.h>

void ParticleSim::Init(std::string title, Vec2d dimensions)
{
  this->title = title;
  this->dimensions = dimensions;
  glfwInit();
  glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3);
  glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 3);
  glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);
  
  #if defined(__APPLE__)
    glfwWindowHint(GLFW_OPENGL_FORWARD_COMPAT, GL_TRUE);
  #endif

// put this in a test
  this->window = glfwCreateWindow(dimensions(0), dimensions(1), "Learning OpenGL", NULL, NULL);
  if(window == NULL){
    this->Exit("Failed to create GLFW window", -1);

  }
  glfwMakeContextCurrent(window);

  if(!gladLoadGLLoader((GLADloadproc)glfwGetProcAddress)){
    this->Exit("Failed to initialise glad", -1);
  }
}

int ParticleSim::Exit(std::string exit_message, int code){
  fmt::println(exit_message);
  glfwTerminate();
  return code;
}
