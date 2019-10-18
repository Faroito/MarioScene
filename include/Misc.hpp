//
// Created by Timothée Couble on 17/10/2019.
//

#ifndef MISC_HPP
# define MISC_HPP

struct Vertex {
    glm::vec3 pos;
    glm::vec4 color;
};

std::string readShader(const std::string &name);

#endif /* !MISC_HPP */
