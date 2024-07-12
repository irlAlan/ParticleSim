#ifndef VOXEL_ENGINE
#define VOXEL_ENGINE

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
};
} // namespace VEngine
#endif // !VOXEL_ENGINE
