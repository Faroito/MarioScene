//
// Created by Timothée Couble on 17/10/2019.
//

#include "Misc.hpp"

std::vector<Vertex> loader::getExampleVertex(int i) {
    std::vector<Vertex> triangle = {
            {glm::vec3(0.5f, -0.5f, 0.5f), glm::vec3(1, 0, 0), glm::vec2(1, 1)},
            {glm::vec3(0.5f, 0.5f, 0.5f), glm::vec3(0, 1, 0), glm::vec2(1, 0)},
            {glm::vec3(-0.5f, 0.5f, 0.5f), glm::vec3(0, 0, 1), glm::vec2(0, 0)},
            {glm::vec3(-0.5f, -0.5f, 0.5f), glm::vec3(1, 1, 0), glm::vec2(0, 1)}
    };
    std::vector<Vertex> cube = {
            {glm::vec3(-0.5f, -0.5f, -0.5f), glm::vec3(0.0f, 0.0f, -1.0f), glm::vec2(0, 0)}, // back
            {glm::vec3(0.5f, -0.5f, -0.5f),  glm::vec3(0.0f, 0.0f, -1.0f), glm::vec2(1, 0)},
            {glm::vec3(0.5f, 0.5f, -0.5f),   glm::vec3(0.0f, 0.0f, -1.0f), glm::vec2(1, 1)},
            {glm::vec3(-0.5f, 0.5f, -0.5f),  glm::vec3(0.0f, 0.0f, -1.0f), glm::vec2(0, 1)},

            {glm::vec3(-0.5f, -0.5f, 0.5f),  glm::vec3(0.0f, 0.0f, 1.0f), glm::vec2(0, 0)}, // front
            {glm::vec3(0.5f, -0.5f, 0.5f),   glm::vec3(0.0f, 0.0f, 1.0f), glm::vec2(1, 0)},
            {glm::vec3(0.5f, 0.5f, 0.5f),    glm::vec3(0.0f, 0.0f, 1.0f), glm::vec2(1, 1)},
            {glm::vec3(-0.5f, 0.5f, 0.5f),   glm::vec3(0.0f, 0.0f, 1.0f), glm::vec2(0, 1)},

            {glm::vec3(-0.5f, 0.5f, 0.5f),   glm::vec3(-1.0f, 0.0f, 0.0f), glm::vec2(1, 0)}, // left
            {glm::vec3(-0.5f, 0.5f, -0.5f),  glm::vec3(-1.0f, 0.0f, 0.0f), glm::vec2(1, 1)},
            {glm::vec3(-0.5f, -0.5f, -0.5f), glm::vec3(-1.0f, 0.0f, 0.0f), glm::vec2(0, 1)},
            {glm::vec3(-0.5f, -0.5f, 0.5f),  glm::vec3(-1.0f, 0.0f, 0.0f), glm::vec2(0, 0)},

            {glm::vec3(0.5f,  0.5f,  0.5f),   glm::vec3(1.0f,  0.0f,  0.0f), glm::vec2(1, 0)}, // right
            {glm::vec3(0.5f,  0.5f, -0.5f),   glm::vec3(1.0f,  0.0f,  0.0f), glm::vec2(1, 1)},
            {glm::vec3(0.5f, -0.5f, -0.5f),   glm::vec3(1.0f,  0.0f,  0.0f), glm::vec2(0, 1)},
            {glm::vec3(0.5f, -0.5f,  0.5f),   glm::vec3(1.0f,  0.0f,  0.0f), glm::vec2(0, 0)},

            {glm::vec3(-0.5f, -0.5f, -0.5f),   glm::vec3(0.0f, -1.0f,  0.0f), glm::vec2(0, 1)}, // bottom
            {glm::vec3(0.5f, -0.5f, -0.5f),   glm::vec3(0.0f, -1.0f,  0.0f), glm::vec2(1, 1)},
            {glm::vec3(0.5f, -0.5f,  0.5f),   glm::vec3(0.0f, -1.0f,  0.0f), glm::vec2(1, 0)},
            {glm::vec3(-0.5f, -0.5f,  0.5f),   glm::vec3(0.0f, -1.0f,  0.0f), glm::vec2(0, 0)},

            {glm::vec3(-0.5f,  0.5f, -0.5f),   glm::vec3(0.0f,  1.0f,  0.0f), glm::vec2(0, 1)}, // top
            {glm::vec3(0.5f,  0.5f, -0.5f),   glm::vec3(0.0f,  1.0f,  0.0f), glm::vec2(1, 1)},
            {glm::vec3(0.5f,  0.5f,  0.5f),   glm::vec3(0.0f,  1.0f,  0.0f), glm::vec2(1, 0)},
            {glm::vec3(-0.5f,  0.5f,  0.5f),   glm::vec3(0.0f,  1.0f,  0.0f), glm::vec2(0, 0)},
    };

    if (i == 1)
        return cube;
    else
        return triangle;
}

std::vector<unsigned int> loader::getExampleIndices(int i) {
    std::vector<unsigned int> triangle = {
            0, 1, 3,
            1, 2, 3
    };
    std::vector<unsigned int> cube = {
            0, 1, 2, // back
            0, 3, 2,
            4, 5, 6, // front
            4, 7, 6,
            8, 9, 10, // left
            8, 11, 10,
            12, 13, 14, // right
            12, 15, 14,
            16, 17, 18, // bottom
            16, 19, 18,
            20, 21, 22, // top
            20, 23, 22
    };

    if (i == 1)
        return cube;
    else
        return triangle;
}
