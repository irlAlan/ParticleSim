#ifndef TYPES_H
#define TYPES_H

#include <Eigen/Dense>

namespace VoxelEngine{
  namespace Types{
    using Vec2d = Eigen::Matrix<int, 2,1>;
    using RGBA = Eigen::Matrix<float, 1, 4>;
  }
}

#endif // TYPES_H
