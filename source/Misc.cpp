//
// Created by Timothée Couble on 17/10/2019.
//

#include "Misc.hpp"

std::vector<Vertex> scene::getExampleVertex(int i) {
    std::vector<Vertex> triangle = {
            {glm::vec3(0.5f, -0.5f, 0.5f), glm::vec3(1, 0, 0), glm::vec2(1, 1)},
            {glm::vec3(0.5f, 0.5f, 0.5f), glm::vec3(0, 1, 0), glm::vec2(1, 0)},
            {glm::vec3(-0.5f, 0.5f, 0.5f), glm::vec3(0, 0, 1), glm::vec2(0, 0)},
            {glm::vec3(-0.5f, -0.5f, 0.5f), glm::vec3(1, 1, 0), glm::vec2(0, 1)}
    };
    std::vector<Vertex> cube = {
            {glm::vec3(0.5f, -0.5f, 0.5f), glm::vec3(0, 0, 1)},
            {glm::vec3(0.5f, 0.5f, 0.5f), glm::vec3(0, 0, 1), glm::vec2(1, 0)},
            {glm::vec3(-0.5f, 0.5f, 0.5f), glm::vec3(0, 0, 1), glm::vec2(0, 0)},
            {glm::vec3(-0.5f, -0.5f, 0.5f), glm::vec3(0, 0, 1), glm::vec2(0, 1)},

            {glm::vec3(0.5f, -0.5f, -0.5f), glm::vec3(0, 0, -1)},
            {glm::vec3(0.5f, 0.5f, -0.5f), glm::vec3(0, 0, -1)},
            {glm::vec3(-0.5f, 0.5f, -0.5f), glm::vec3(0, 0, -1), glm::vec2(0, 0)},
            {glm::vec3(-0.5f, -0.5f, -0.5f), glm::vec3(0, 0, -1), glm::vec2(0, 1)}
    };

    std::vector<Vertex> normalCube = {
            {glm::vec3(-0.5f, -0.5f, -0.5f), glm::vec3(0.0f, 0.0f, -1.0f), glm::vec2(1, 1)}, // back
            {glm::vec3(0.5f, -0.5f, -0.5f),  glm::vec3(0.0f, 0.0f, -1.0f), glm::vec2(1, 0)},
            {glm::vec3(0.5f, 0.5f, -0.5f),   glm::vec3(0.0f, 0.0f, -1.0f), glm::vec2(0, 0)},
            {glm::vec3(-0.5f, 0.5f, -0.5f),  glm::vec3(0.0f, 0.0f, -1.0f), glm::vec2(0, 1)},

            {glm::vec3(-0.5f, -0.5f, 0.5f),  glm::vec3(0.0f, 0.0f, 1.0f), glm::vec2(1, 1)}, // front
            {glm::vec3(0.5f, -0.5f, 0.5f),   glm::vec3(0.0f, 0.0f, 1.0f), glm::vec2(1, 0)},
            {glm::vec3(0.5f, 0.5f, 0.5f),    glm::vec3(0.0f, 0.0f, 1.0f), glm::vec2(0, 0)},
            {glm::vec3(-0.5f, 0.5f, 0.5f),   glm::vec3(0.0f, 0.0f, 1.0f), glm::vec2(0, 1)},

            {glm::vec3(-0.5f, 0.5f, 0.5f),   glm::vec3(-1.0f, 0.0f, 0.0f), glm::vec2(1, 1)}, // left
            {glm::vec3(-0.5f, 0.5f, -0.5f),  glm::vec3(-1.0f, 0.0f, 0.0f), glm::vec2(1, 0)},
            {glm::vec3(-0.5f, -0.5f, -0.5f), glm::vec3(-1.0f, 0.0f, 0.0f), glm::vec2(0, 0)},
            {glm::vec3(-0.5f, -0.5f, 0.5f),  glm::vec3(-1.0f, 0.0f, 0.0f), glm::vec2(0, 1)},

            {glm::vec3(0.5f,  0.5f,  0.5f),   glm::vec3(1.0f,  0.0f,  0.0f), glm::vec2(1, 1)}, // right
            {glm::vec3(0.5f,  0.5f, -0.5f),   glm::vec3(1.0f,  0.0f,  0.0f), glm::vec2(1, 0)},
            {glm::vec3(0.5f, -0.5f, -0.5f),   glm::vec3(1.0f,  0.0f,  0.0f), glm::vec2(0, 0)},
            {glm::vec3(0.5f, -0.5f,  0.5f),   glm::vec3(1.0f,  0.0f,  0.0f), glm::vec2(0, 1)},

            {glm::vec3(-0.5f, -0.5f, -0.5f),   glm::vec3(0.0f, -1.0f,  0.0f), glm::vec2(1, 1)}, // bottom
            {glm::vec3(0.5f, -0.5f, -0.5f),   glm::vec3(0.0f, -1.0f,  0.0f), glm::vec2(1, 0)},
            {glm::vec3(0.5f, -0.5f,  0.5f),   glm::vec3(0.0f, -1.0f,  0.0f), glm::vec2(0, 0)},
            {glm::vec3(-0.5f, -0.5f,  0.5f),   glm::vec3(0.0f, -1.0f,  0.0f), glm::vec2(0, 1)},

            {glm::vec3(-0.5f,  0.5f, -0.5f),   glm::vec3(0.0f,  1.0f,  0.0f), glm::vec2(1, 1)}, // top
            {glm::vec3(0.5f,  0.5f, -0.5f),   glm::vec3(0.0f,  1.0f,  0.0f), glm::vec2(1, 0)},
            {glm::vec3(0.5f,  0.5f,  0.5f),   glm::vec3(0.0f,  1.0f,  0.0f), glm::vec2(0, 0)},
            {glm::vec3(-0.5f,  0.5f,  0.5f),   glm::vec3(0.0f,  1.0f,  0.0f), glm::vec2(0, 1)}
    };

    if (i == 1)
        return cube;
    else if (i == 2)
        return normalCube;
    else
        return triangle;
}

std::vector<unsigned int> scene::getExampleIndices(int i) {
    std::vector<unsigned int> triangle = {
            0, 1, 3,
            1, 2, 3
    };
    std::vector<unsigned int> cube = {
            1, 0, 3, // front
            1, 2, 3,
            7, 6, 5, // back
            7, 4, 5,
            6, 7, 3, // left
            6, 2, 3,
            1, 5, 4, // right
            1, 0, 4,
            6, 5, 1, // top
            6, 2, 1,
            3, 7, 4, // bottom
            3, 0, 4
    };

    std::vector<unsigned int> normalCube = {
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
    else if (i == 2)
        return normalCube;
    else
        return triangle;
}
