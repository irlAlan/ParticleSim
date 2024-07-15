#ifndef VOXEL_ENGINE
#define VOXEL_ENGINE

#include "VEngine/Window.h"
namespace VEngine {
class VoxelEngine {
public:
  void Init();
  void Cleanup();

  // state management

  // Event handling
  void HandleEvents();
  void Update();
  void Draw();
  bool Running() { return _running; }

private:
  bool _running;
  Window win{"Hey Bozo", {500, 500}};

};
} // namespace VEngine
#endif // !VOXEL_ENGINE
