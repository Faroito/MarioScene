//
// Created by Timothée Couble on 18/10/2019.
//

#ifndef MESH_HPP
# define MESH_HPP

#include "glm/glm.hpp"
#include "glm/gtc/matrix_transform.hpp"
#include "glm/gtc/type_ptr.hpp"

#include "Lib.hpp"

namespace scene {
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
        unsigned int id;
        string type;
    };
}

#endif /* !MESH_HPP */
