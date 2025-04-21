#ifndef WINDOW_H
#define WINDOW_H

#include <Eigen/Dense>
#include <Eigen/src/Core/Matrix.h>


class Window{
public:
  using Vec2d = Eigen::Vector2<int>;
public:
  Window(std::string title, Vec2d dim);
  ~Window();

};

#endif
