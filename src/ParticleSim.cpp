#include <ParticleSim/ParticleSim.h>

// TODO
// Change this class 


//void ParticleSim::Init(std::string title, Vec2d dimensions)
//{
//  this->title = title;
//  this->dimensions = dimensions;
//  glfwInit();
//  glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3);
//  glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 3);
//  glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);
//  
//  #if defined(__APPLE__)
//    glfwWindowHint(GLFW_OPENGL_FORWARD_COMPAT, GL_TRUE);
//  #endif
//
//// put this in a test
//  this->window = glfwCreateWindow(dimensions(0), dimensions(1), "Learning OpenGL", nullptr, nullptr);
//  if(window == nullptr){
//    this->Exit("Failed to create GLFW window", -1);
//
//  }
//  glfwMakeContextCurrent(window);
//  if(!gladLoadGLLoader((GLADloadproc)glfwGetProcAddress)){
//    this->Exit("Failed to initialise glad", -1);
//  }
//
//  glViewport(0, 0, dimensions.x(), dimensions.y());
//  glfwSetFramebufferSizeCallback(window, framebuffer_size_callback);
//}
//
//
//void ParticleSim::processInput(GLFWwindow* window){
//  if(glfwGetKey(window, GLFW_KEY_ESCAPE) == GLFW_PRESS)
//    glfwSetWindowShouldClose(window, true);
//}
//
//int ParticleSim::Run(){
//  while(!glfwWindowShouldClose(window)){
//    // INPUTS
//    processInput(window);
//
//    // render commands
//    ClearWindow(RGBA{0.2f, 0.3f, 0.3f,1.0f});
//
//    // events and swap buffers
//    glfwSwapBuffers(window);
//    glfwPollEvents();
//  }
//  return 0;
//}
//
//void ParticleSim::ClearWindow(RGBA col){
//    glClearColor(col.x(), col.y(), col.z(), col.w());
//    glClear(GL_COLOR_BUFFER_BIT);
//}
//
//void ParticleSim::framebuffer_size_callback(GLFWwindow* window, int width, int height){
//  glViewport(0, 0, width, height);
//}
//
//int ParticleSim::Exit(std::string exit_message, int code){
//  fmt::print("message: {}\n code: {}\n", exit_message, code);
//  glfwTerminate();
//  return code;
//}
