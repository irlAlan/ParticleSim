#include <VEngine/VoxelEngine.h>
#include <fmt/core.h>

int main() {
  VEngine::Window win{"hey there", {450, 340}};

  while(win.windowIsOpen()){
    win.displayWindow();
  }


  return 0;
}
