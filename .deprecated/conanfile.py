from conan import ConanFile
from conan.tools.cmake import cmake_layout, CMakeToolchain
from conan.tools.system.package_manager import Apt, Yum, PacMan, Zypper


class ExampleRecipe(ConanFile):
    settings = "os", "compiler", "build_type", "arch"
    generators = "CMakeDeps", "CMakeToolchain"

    #def system_requirements(self):
    #    # depending on the platform or the tools.system.package_manager:tool configuration
    #    # only one of these will be executed
    #    Apt(self).install(["libgl-dev"])
    #    Yum(self).install(["libglvnd-devel"])
    #    PacMan(self).install(["libxres"])
    #    Zypper(self).install(["Mesa-libGL-devel"])

    #def generate(self):
    #    tc = CMakeToolchain(self)
    #    tc = CMakeDeps(self)
    #    tc.cache_variables["CMAKE_EXPORT_COMPILE_COMMANDS"] = "ON"
    #        tc.generate()

    def requirements(self):
        self.requires("fmt/11.0.1")
        #self.requires("gtest/1.14.0")
        #self.requires("glfw/3.4")
        #self.requires("glad/0.1.36")
        #self.requires("eigen/3.4.0")

    def layout(self):
        cmake_layout(self)
