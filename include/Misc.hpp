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

namespace loader {
    struct Vertex {
        glm::vec3 position;
        glm::vec3 normal;
        glm::vec2 textureCord;
    };

    enum class TextureType {
        TEXTURE_DIFFUSE,
        TEXTURE_SPECULAR
    };

    struct Texture {
        GLuint id;
        std::string path;
        TextureType type;
    };

    std::vector<Vertex> getExampleVertex(int i);
    std::vector<unsigned int> getExampleIndices(int i);
}

#endif /* !MISC_HPP */
