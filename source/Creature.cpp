//
// Created by Timothée Couble on 02/11/2019.
//

#include "Creature.hpp"

scene::Creature::Creature(ModelType type) : AObject(type) {}

scene::Creature::Creature(const scene::AObject &other) : AObject(other) {}

void scene::Creature::init() {
    _offset += _position;
    _baseOrientation = _orientation;
}

void scene::Creature::draw(const scene::Models_t &models, const gl_wrapper::Shaders_t &shaders) {
    move();
    if (getType() != ModelType::MUSHROOM)
        orient();
    AObject::draw(models, shaders);
}

void scene::Creature::orient() {
    auto left_vector = glm::normalize(_position - _oldPosition);

    double pitch = 0;
    if (left_vector.y < 0)
        pitch = glm::asin(left_vector.y) * (180 / M_PI);
    else
        pitch = -glm::asin(left_vector.y) * (180 / M_PI);
    double yaw = glm::atan(left_vector.x, left_vector.z) * (180 / M_PI);

    _orientation = glm::vec3(pitch, yaw, 1.0f) + _baseOrientation;
    _oldPosition = _position;
}

void scene::Creature::move() {
    auto aTime = (float) glfwGetTime();

    _position = glm::vec3(cos(aTime) / 2.0f, 0.0f, 0.0f);
}
