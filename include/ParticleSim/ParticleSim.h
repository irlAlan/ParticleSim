#ifndef PARTICLE_SIM_H
#define PARTICLE_SIM_H

// TODO:
// Change this class 
//
#include <VoxelEngine/CoreIncludes.h>

class ParticleSim{
  using Vec2d = VoxelEngine::Types::Vec2d;
  using RGBA = VoxelEngine::Types::RGBA;
public:
  int Run();
protected:
  ParticleSim()  = default;
  ~ParticleSim() = default;

  void Init(std::string title, Vec2d dimensions);
  int Exit(std::string exit_message, int code);

  void processInput(GLFWwindow* window);

  static void framebuffer_size_callback(GLFWwindow* window, int width, int height);
  void ClearWindow(RGBA col);

private:
  GLFWwindow* window;
  Vec2d dimensions;
  std::string title;
};

#endif // PARTICLE_SIM_H
