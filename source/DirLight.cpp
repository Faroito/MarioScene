//
// Created by Timothée Couble on 19/10/2019.
//

#include "DirLight.hpp"

scene::DirLight::DirLight(const glm::vec3 &direction) : _direction(direction), Light() {}

void scene::DirLight::setDirection(const glm::vec3 &direction) {
    _direction = direction;
}

const glm::vec3 &scene::DirLight::getDirection() const {
    return _direction;
}
