#ifndef PARTICLE_SIM_H
#define PARTICLE_SIM_H

#include <string>
#include <Eigen/Dense>
#include <glad/glad.h>
#include <GLFW/glfw3.h>
#include <fmt/core.h>

class ParticleSim{
public:
  using Vec2d = Eigen::Matrix<int, 2,1>;
public:
  ParticleSim()  = default;
  ~ParticleSim() = default;

  void Init(std::string title, Vec2d dimensions);
  int Exit(std::string exit_message, int code);

private:
  GLFWwindow *window;
  Vec2d dimensions;
  std::string title;
};

#endif // PARTICLE_SIM_H
