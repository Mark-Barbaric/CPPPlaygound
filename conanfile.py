from conans import ConanFile

class CustomConanFile(ConanFile):

    settings = 'os', 'os_build', 'compiler', 'build_type', 'arch', 'arch_build'

    generators = 'cmake', 'cmake_find_package', 'cmake_paths', 'txt'

    def requirements(self):
        self.requires('gtest/1.8.1@bincrafters/stable')