//
// Created by Timothée Couble on 19/10/2019.
//

#include "Light.hpp"

void scene::Light::setAmbient(const glm::vec3 &ambient) {
    _ambient = ambient;
}

void scene::Light::setDiffuse(const glm::vec3 &diffuse) {
    _diffuse = diffuse;
}

void scene::Light::setSpecular(const glm::vec3 &specular) {
    _specular = specular;
}

const glm::vec3 &scene::Light::getAmbient() const {
    return _ambient;
}

const glm::vec3 &scene::Light::getDiffuse() const {
    return _diffuse;
}

const glm::vec3 &scene::Light::getSpecular() const {
    return _specular;
}
