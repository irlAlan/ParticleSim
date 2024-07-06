#ifndef PARTICLE_SIM_H
#define PARTICLE_SIM_H

#include <ParticleSim/CoreIncludes.h>

class ParticleSim{
public:
  int Run();
protected:
  ParticleSim()  = default;
  ~ParticleSim() = default;

  void Init(std::string title, Types::Vec2d dimensions);
  int Exit(std::string exit_message, int code);

  void processInput(GLFWwindow* window);

  static void framebuffer_size_callback(GLFWwindow* window, int width, int height);
  void ClearWindow(Types::RGBA col);

private:
  GLFWwindow* window;
  Types::Vec2d dimensions;
  std::string title;
};

#endif // PARTICLE_SIM_H
