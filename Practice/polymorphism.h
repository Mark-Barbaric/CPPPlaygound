#pragma once
#include <iostream>

namespace FunctionOverloading {

    void Function() {
        std::cout << "Function" << std::endl;
    }

    void Function(std::string& s1) {
        std::cout << s1 << std::endl;
    }

    std::string Function(std::string& s1, std::string& s2) {
        return "Function";
    }
}
