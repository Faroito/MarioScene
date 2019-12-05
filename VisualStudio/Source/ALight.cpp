//
// Created by Timothée Couble on 19/10/2019.
//

#include "ALight.hpp"

scene::ALight::ALight(const std::string &name) : _name(name) {}

void scene::ALight::setAmbient(const glm::vec3 &ambient) {
    _ambient = ambient;
}

void scene::ALight::setDiffuse(const glm::vec3 &diffuse) {
    _diffuse = diffuse;
}

void scene::ALight::setSpecular(const glm::vec3 &specular) {
    _specular = specular;
}

const glm::vec3 &scene::ALight::getAmbient() const {
    return _ambient;
}

void scene::ALight::setShader(const gl_wrapper::Shader_ptr_t &shader) const {
    shader->setUniformVector3(getUniformName("ambient").c_str(), _ambient);
    shader->setUniformVector3(getUniformName("diffuse").c_str(), _diffuse);
    shader->setUniformVector3(getUniformName("specular").c_str(), _specular);
}

std::string scene::ALight::getUniformName(const std::string &type) const {
    return std::string(_name + "." + type);
}
