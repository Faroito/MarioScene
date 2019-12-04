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

namespace gl_wrapper {
    enum class ShaderType {
        LIGHT,
        MODEL,
        TEXTURE_DIFFUSE,
        TEXTURE_SPECULAR,
        FRAMEBUFFER_TEXTURE
    };
}

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
        TEXTURE_SPECULAR,
        FRAMEBUFFER_TEXTURE
    };

    struct Texture {
        GLuint id = 0;
        std::string path;
        TextureType type = TextureType::TEXTURE_DIFFUSE;
    };

    typedef std::vector<loader::Texture> Textures_t;

    struct Material {
        glm::vec3 ambient = glm::vec3(0.04f, 0.04f, 0.04f);
        glm::vec3 diffuse = glm::vec3(0.5f, 0.5f, 0.5f);
        glm::vec3 specular = glm::vec3(0.0f, 0.0f, 0.0f);
        float specularExponent = 10.0;
        float opticalDensity = 1.0;
        float shininess = 64.0;
        int ilum = 4;
        gl_wrapper::ShaderType type = gl_wrapper::ShaderType::MODEL;
    };

    typedef std::unordered_map<std::string, loader::Material> Materials_t;
    typedef std::unordered_map<std::string, loader::Textures_t> TexturesMap_t;

    Vertices_t getStandardVertices(int i = 0);
    Indices_t getStandardIndices(int i = 0);
}

namespace scene {
    enum class ModelType {
        UNKNOWN = 0,
        BLOCK,
        GRASS_BLOCK,
        QUESTION_BLOCK,
        PIPE,
        MUSHROOM,
        GOOMPA,
        PIRANHA_PLANT,
        BULLET_BILL
    };
}

#endif /* !MISC_HPP */
