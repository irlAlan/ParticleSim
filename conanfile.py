from conan import ConanFile
from conan.tools.cmake import cmake_layout, CMakeToolchain


class ExampleRecipe(ConanFile):
    settings = "os", "compiler", "build_type", "arch"
    generators = "CMakeDeps", "CMakeToolchain"


    def generate(self):
        tc = CMakeToolchain(self)
        tc.cache_variables["CMAKE_EXPORT_COMPILE_COMMANDS"] = "ON"
    #        tc.generate()

    def requirements(self):
        self.requires("fmt/11.0.0")
        self.requires("gtest/1.14.0")
        self.requires("glfw/3.4")
        self.requires("glad/0.1.36")
        self.requires("eigen/3.4.0")

    def layout(self):
        cmake_layout(self)
