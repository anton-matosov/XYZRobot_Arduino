from conans import ConanFile, CMake, tools
import os

class App(ConanFile):
    settings = "os", "compiler", "build_type", "arch"
    generators = ["cmake", "virtualenv", "virtualbuildenv", "virtualrunenv"]

    def build(self):
        cmake = CMake(self)
        cmake.configure()

    def imports(self):
        self.copy("*.dll", dst="bin", src="bin")
        self.copy("*.dylib*", dst="bin", src="lib")

    def test(self):
        self.output.success("Done")
