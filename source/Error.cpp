//
// Created by Timothée Couble on 18/10/2019.
//

#include "Error.hpp"

void error::callbackGLFW(int error, const char* description) {
    std::cerr << "Error GLFW: " << description << std::endl;
}