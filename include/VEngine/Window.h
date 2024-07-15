#ifndef WINDOWSETTINGS_H
#define WINDOWSETTINGS_H

#include <VEngine/CoreIncludes.h>
#include <fmt/core.h>

namespace VEngine {

class Window {
public:
  Window(std::string title, Types::Vec2d dim);


  void displayWindow();
  std::string getTitle() const { return _title; }
  Types::Vec2d getDimensions() const { return _dimensions; }
  Types::RGBA getBackgroundCol() const { return _backgroundCol; }

  bool windowIsOpen();
  void exitWindow(std::string message, int exit_code);

private:
  GLFWwindow *window;
  std::string _title{"hey"};
  Types::Vec2d _dimensions{100, 100};
  Types::RGBA _backgroundCol{0.7f, 0.7f, 0.7f, 1.0f};

//private:

//void static viewportSizeChange(GLFWwindow* window, int width, int height);

public:
  // copy constructor
  Window(const Window &other)
      : _title(other._title), _dimensions(other._dimensions),
        _backgroundCol(other._backgroundCol) {}
  // copy assignment operator
  Window &operator=(const VEngine::Window &other) {
    if (this != &other) {
      *this = other;
    }
    return *this;
  }

  // Move Constructor
  Window(Window &&other) noexcept
      : _title(other._title), _dimensions(other._dimensions),
        _backgroundCol(other._backgroundCol) {
    other._title = "";
    other._backgroundCol = {};
    other._dimensions = {};
  }
  // Move assignment operator
  Window &operator=(Window &&other) {
    if (this != &other) {
      _title = other._title;
      _dimensions = other._dimensions;
      _backgroundCol = other._backgroundCol;

      other._title = "";
      other._dimensions = {};
      other._backgroundCol = {};
    }
    return *this;
  }
  ~Window(){
    exitWindow("closing window", 0);
  }
};
} // namespace VEngine
#endif // !WINDOWSETTINGS_H
