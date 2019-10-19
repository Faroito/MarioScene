//
// Created by Timothée Couble on 17/10/2019.
//

#include "Misc.hpp"

std::vector<VertexColor> scene::getExampleVertex(int i) {
    std::vector<VertexColor> triangle = {
            {glm::vec3(0.5f, -0.5f, 0.5f), glm::vec3(1, 0, 0), /*glm::vec2(1, 1)*/},
            {glm::vec3(0.5f, 0.5f, 0.5f), glm::vec3(0, 1, 0), /*glm::vec2(1, 0)*/},
            {glm::vec3(-0.5f, 0.5f, 0.5f), glm::vec3(0, 0, 1), /*glm::vec2(0, 0)*/},
            {glm::vec3(-0.5f, -0.5f, 0.5f), glm::vec3(1, 1, 0), /*glm::vec2(0, 1)*/}
    };
    std::vector<VertexColor> cube = {
            {glm::vec3(0.5f, -0.5f, 0.5f), glm::vec3(0, 0, 1)},
            {glm::vec3(0.5f, 0.5f, 0.5f), glm::vec3(0, 0, 1)},
            {glm::vec3(-0.5f, 0.5f, 0.5f), glm::vec3(0, 0, 1)},
            {glm::vec3(-0.5f, -0.5f, 0.5f), glm::vec3(0, 0, 1)},

            {glm::vec3(0.5f, -0.5f, -0.5f), glm::vec3(0, 0, -1)},
            {glm::vec3(0.5f, 0.5f, -0.5f), glm::vec3(0, 0, -1)},
            {glm::vec3(-0.5f, 0.5f, -0.5f), glm::vec3(0, 0, -1)},
            {glm::vec3(-0.5f, -0.5f, -0.5f), glm::vec3(0, 0, -1)}
    };

    std::vector<VertexColor> normalCube = {
            {glm::vec3(-0.5f, -0.5f, -0.5f), glm::vec3(0.0f, 0.0f, -1.0f)},
            {glm::vec3(0.5f, -0.5f, -0.5f),  glm::vec3(0.0f, 0.0f, -1.0f)},
            {glm::vec3(0.5f, 0.5f, -0.5f),   glm::vec3(0.0f, 0.0f, -1.0f)},
            {glm::vec3(0.5f, 0.5f, -0.5f),   glm::vec3(0.0f, 0.0f, -1.0f)},
            {glm::vec3(-0.5f, 0.5f, -0.5f),  glm::vec3(0.0f, 0.0f, -1.0f)},
            {glm::vec3(-0.5f, -0.5f, -0.5f), glm::vec3(0.0f, 0.0f, -1.0f)},

            {glm::vec3(-0.5f, -0.5f, 0.5f),  glm::vec3(0.0f, 0.0f, 1.0f)},
            {glm::vec3(0.5f, -0.5f, 0.5f),   glm::vec3(0.0f, 0.0f, 1.0f)},
            {glm::vec3(0.5f, 0.5f, 0.5f),    glm::vec3(0.0f, 0.0f, 1.0f)},
            {glm::vec3(0.5f, 0.5f, 0.5f),    glm::vec3(0.0f, 0.0f, 1.0f)},
            {glm::vec3(-0.5f, 0.5f, 0.5f),   glm::vec3(0.0f, 0.0f, 1.0f)},
            {glm::vec3(-0.5f, -0.5f, 0.5f),  glm::vec3(0.0f, 0.0f, 1.0f)},

            {glm::vec3(-0.5f, 0.5f, 0.5f),   glm::vec3(-1.0f, 0.0f, 0.0f)},
            {glm::vec3(-0.5f, 0.5f, -0.5f),  glm::vec3(-1.0f, 0.0f, 0.0f)},
            {glm::vec3(-0.5f, -0.5f, -0.5f), glm::vec3(-1.0f, 0.0f, 0.0f)},
            {glm::vec3(-0.5f, -0.5f, -0.5f), glm::vec3(-1.0f, 0.0f, 0.0f)},
            {glm::vec3(-0.5f, -0.5f, 0.5f),  glm::vec3(-1.0f, 0.0f, 0.0f)},
            {glm::vec3(-0.5f, 0.5f, 0.5f),   glm::vec3(-1.0f, 0.0f, 0.0f)},

            {glm::vec3(0.5f,  0.5f,  0.5f),   glm::vec3(1.0f,  0.0f,  0.0f)},
            {glm::vec3(0.5f,  0.5f, -0.5f),   glm::vec3(1.0f,  0.0f,  0.0f)},
            {glm::vec3(0.5f, -0.5f, -0.5f),   glm::vec3(1.0f,  0.0f,  0.0f)},
            {glm::vec3(0.5f, -0.5f, -0.5f),   glm::vec3(1.0f,  0.0f,  0.0f)},
            {glm::vec3(0.5f, -0.5f,  0.5f),   glm::vec3(1.0f,  0.0f,  0.0f)},
            {glm::vec3(0.5f,  0.5f,  0.5f),   glm::vec3(1.0f,  0.0f,  0.0f)},

            {glm::vec3(-0.5f, -0.5f, -0.5f),   glm::vec3(0.0f, -1.0f,  0.0f)},
            {glm::vec3(0.5f, -0.5f, -0.5f),   glm::vec3(0.0f, -1.0f,  0.0f)},
            {glm::vec3(0.5f, -0.5f,  0.5f),   glm::vec3(0.0f, -1.0f,  0.0f)},
            {glm::vec3(0.5f, -0.5f,  0.5f),   glm::vec3(0.0f, -1.0f,  0.0f)},
            {glm::vec3(-0.5f, -0.5f,  0.5f),   glm::vec3(0.0f, -1.0f,  0.0f)},
            {glm::vec3(-0.5f, -0.5f, -0.5f),   glm::vec3(0.0f, -1.0f,  0.0f)},

            {glm::vec3(-0.5f,  0.5f, -0.5f),   glm::vec3(0.0f,  1.0f,  0.0f)},
            {glm::vec3(0.5f,  0.5f, -0.5f),   glm::vec3(0.0f,  1.0f,  0.0f)},
            {glm::vec3(0.5f,  0.5f,  0.5f),   glm::vec3(0.0f,  1.0f,  0.0f)},
            {glm::vec3(0.5f,  0.5f,  0.5f),   glm::vec3(0.0f,  1.0f,  0.0f)},
            {glm::vec3(-0.5f,  0.5f,  0.5f),   glm::vec3(0.0f,  1.0f,  0.0f)},
            {glm::vec3(-0.5f,  0.5f, -0.5f),   glm::vec3(0.0f,  1.0f,  0.0f)}
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
            1, 2, 3, // front
            4, 5, 6,
            7, 8, 9, // back
            10, 11, 12,
            13, 14, 15, // left
            16, 17, 18,
            19, 20, 21, // right
            22, 23, 24,
            25, 26, 27, // top
            28, 29, 30,
            31, 32, 33, // bottom
            34, 35, 36
    };

    if (i == 1)
        return cube;
    else if (i == 2)
        return normalCube;
    else
        return triangle;
}
