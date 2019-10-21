//
// Created by Timothée Couble on 19/10/2019.
//

#include "DirLight.hpp"

scene::DirLight::DirLight(const glm::vec3 &direction)
    : _direction(direction), ALight("dirLight") {}

void scene::DirLight::setDirection(const glm::vec3 &direction) {
    _direction = direction;
}

const glm::vec3 &scene::DirLight::getDirection() const {
    return _direction;
}

void scene::DirLight::setShader(const gl_wrapper::Shader_ptr_t &shader) const {
    ALight::setShader(shader);
    shader->setUniformVector3(getUniformName("direction").c_str(), _direction);
}
