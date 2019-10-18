//
// Created by Timothée Couble on 17/10/2019.
//

#include <iostream>
#include <fstream>
#include <string>
#include <sstream>
#include <Misc.hpp>

std::string scene::readShader(const std::string &name) {
    std::string vs_text;
    std::ifstream vs_file(name);

    std::string vs_line;
    if (vs_file.is_open()) {

        while (std::getline(vs_file, vs_line)) {
            vs_text += vs_line;
            vs_text += '\n';
        }
        vs_file.close();
    }
    return vs_text;
}

std::vector<VertexColor> scene::getExampleVertex(int i) {
    std::vector<VertexColor> triangle = {
            {glm::vec3(0.5f, -0.5f, 0.5f), glm::vec4(1, 0, 0, 1)},
            {glm::vec3(0.5f, 0.5f, 0.5f), glm::vec4(0, 1, 0, 1)},
            {glm::vec3(-0.5f, 0.5f, 0.5f), glm::vec4(0, 0, 1, 1)},
            {glm::vec3(-0.5f, -0.5f, 0.5f), glm::vec4(1, 1, 0, 1)}
    };
    std::vector<VertexColor> cube = {
            {glm::vec3(0.5f, -0.5f, 0.5f), glm::vec4(1, 0, 0, 1)},
            {glm::vec3(0.5f, 0.5f, 0.5f), glm::vec4(0, 1, 0, 1)},
            {glm::vec3(-0.5f, 0.5f, 0.5f), glm::vec4(0, 0, 1, 1)},
            {glm::vec3(-0.5f, -0.5f, 0.5f), glm::vec4(1, 1, 0, 1)},

            {glm::vec3(0.5f, -0.5f, -0.5f), glm::vec4(0, 1, 0, 1)},
            {glm::vec3(0.5f, 0.5f, -0.5f), glm::vec4(0, 0, 1, 1)},
            {glm::vec3(-0.5f, 0.5f, -0.5f), glm::vec4(1, 0, 0, 1)},
            {glm::vec3(-0.5f, -0.5f, -0.5f), glm::vec4(0, 1, 1, 1)}
    };

    if (i == 1)
        return cube;
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

    if (i == 1)
        return cube;
    else
        return triangle;
}
