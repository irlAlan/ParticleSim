#include <VEngine/VoxelEngine.h>
#include <fmt/core.h>

void VEngine::VoxelEngine::Init() { 
  fmt::print("Title: {}\n Size: {}x{}\n", win.getTitle(), win.getDimensions().x(), win.getDimensions().y());
}

void VEngine::VoxelEngine::Cleanup() {}

void VEngine::VoxelEngine::Draw() {}

void VEngine::VoxelEngine::Update() {}

void VEngine::VoxelEngine::HandleEvents() {}
