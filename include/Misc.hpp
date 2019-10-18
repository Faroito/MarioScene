//
// Created by Timothée Couble on 17/10/2019.
//

#ifndef MISC_HPP
# define MISC_HPP

#include <iostream>
#include <string>
#include <vector>

#include "glm/glm.hpp"

#include "Lib.hpp"

struct VertexColor {
    glm::vec3 pos;
    glm::vec4 color;
};

struct Vertex {
    glm::vec3 position;
    glm::vec3 normal;
    glm::vec2 texCord;
};

struct Texture {
    GLuint id;
    std::string type;
};

namespace scene {
    std::string readShader(const std::string &name);

    std::vector<VertexColor> getExampleVertex(int i);
    std::vector<unsigned int> getExampleIndices(int i);
}

#endif /* !MISC_HPP */
