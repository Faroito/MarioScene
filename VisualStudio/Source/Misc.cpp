//
// Created by Timothée Couble on 17/10/2019.
//

#include "Misc.hpp"

loader::Vertices_t loader::getStandardVertices(int i) {
    loader::Vertices_t plane = {
            {glm::vec3(-1.0f, 1.0f, 0.0f), glm::vec3(0, 1, 0), glm::vec2(0, 0)},
            {glm::vec3(-1.0f, -1.0f, 0.0f), glm::vec3(0, 0, 0), glm::vec2(0, 1)},
            {glm::vec3(1.0f, -1.0f, 0.0f), glm::vec3(1, 0, 0), glm::vec2(1, 1)},
            {glm::vec3(-1.0f, 1.0f, 0.0f), glm::vec3(0, 1, 0), glm::vec2(0, 0)},
            {glm::vec3(1.0f, -1.0f, 0.0f), glm::vec3(1, 0, 0), glm::vec2(1, 1)},
            {glm::vec3(1.0f, 1.0f, 0.0f), glm::vec3(1, 1, 0), glm::vec2(1, 0)}
    };
    loader::Vertices_t cube = {
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
    loader::Vertices_t pyramid = {
            {glm::vec3(-1.38446, 0.061836, -2.39795), glm::vec3(0, -1, 0), glm::vec2(0.375, 0.033494)},
            {glm::vec3(2.76891, 0.061836, 0), glm::vec3(0, -1, 0), glm::vec2(0.75, 0.25)},
            {glm::vec3(-1.38446, 0.061836, 2.39795), glm::vec3(0, -1, 0), glm::vec2(0.375, 0.466506)},
            {glm::vec3(-1.38446, 0.061836, -2.39795), glm::vec3(-0.955824, 0.293939, -0), glm::vec2(0.25, 0.5)},
            {glm::vec3(-1.38446, 0.061836, 2.39795), glm::vec3(-0.955824, 0.293939, -0), glm::vec2(0.416667, 0.5)},
            {glm::vec3(0, 4.56378, 0), glm::vec3(-0.955824, 0.293939, -0), glm::vec2(0.5, 1)},
            {glm::vec3(-1.38446, 0.061836, 2.39795), glm::vec3(0.477912, 0.293939, 0.827768), glm::vec2(0.416667, 0.5)},
            {glm::vec3(2.76891, 0.061836, 0), glm::vec3(0.477912, 0.293939, 0.827768), glm::vec2(0.583333, 0.5)},
            {glm::vec3(0, 4.56378, 0), glm::vec3(0.477912, 0.293939, 0.827768), glm::vec2(0.5, 1)},
            {glm::vec3(2.76891, 0.061836, 0), glm::vec3(0.477912, 0.293939, -0.827768), glm::vec2(0.583333, 0.5)},
            {glm::vec3(-1.38446, 0.061836, -2.39795), glm::vec3(0.477912, 0.293939, -0.827768), glm::vec2(0.75, 0.5)},
            {glm::vec3(0, 4.56378, 0), glm::vec3(0.477912, 0.293939, -0.827768), glm::vec2(0.5, 1)}
    };

    if (i == 1)
        return cube;
    else if (i == 2)
        return pyramid;
    else
        return plane;
}

loader::Indices_t loader::getStandardIndices(int i) {
    loader::Indices_t plane = {
            0, 1, 2,
            3, 4, 5
    };
    loader::Indices_t cube = {
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
    loader::Indices_t pyramid = {
            0, 1, 2,
            3, 4, 5,
            6, 7, 8,
            9, 10, 11
    };

    if (i == 1)
        return cube;
    else if (i == 2)
        return pyramid;
    else
        return plane;
}
