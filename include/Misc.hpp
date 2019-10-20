//
// Created by Timothée Couble on 17/10/2019.
//

#ifndef MISC_HPP
# define MISC_HPP

#include <iostream>
#include <string>
#include <vector>
#include <unordered_map>

#include "glm/glm.hpp"

#include "Lib.hpp"

namespace loader {
    struct Vertex {
        glm::vec3 position;
        glm::vec3 normal;
        glm::vec2 textureCord;
    };

    typedef std::vector<Vertex> Vertices_t;
    typedef std::vector<unsigned int> Indices_t;

    enum class TextureType {
        TEXTURE_DIFFUSE,
        TEXTURE_SPECULAR
    };

    struct Texture {
        GLuint id;
        std::string path;
        TextureType type;
    };

    struct Material {
        glm::vec3 ambient = glm::vec3(0.04f, 0.04f, 0.04f);
        glm::vec3 diffuse = glm::vec3(0.5f, 0.5f, 0.5f);
        glm::vec3 specular = glm::vec3(0.0f, 0.0f, 0.0f);
        float specularExponent = 10.0;
        float opticalDensity = 1.0;
        float shininess = 64.0;
        int ilum = 4;
    };

    typedef std::unordered_map<std::string, loader::Material> Materials_t;

    Vertices_t getExampleVertex(int i);
    Indices_t getExampleIndices(int i);
}

#endif /* !MISC_HPP */
