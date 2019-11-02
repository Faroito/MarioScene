//
// Created by Timothée Couble on 02/11/2019.
//

#include "AObject.hpp"

scene::AObject::AObject(ModelType type) : _type(type) {}

void scene::AObject::init() {}

void scene::AObject::draw(const scene::Models_t &models, const gl_wrapper::Shaders_t &shaders) {
    if (_type == ModelType::UNKNOWN)
        return;
    models.at(_type)->setPosition(_position + _offset);
    models.at(_type)->setOrientation(_orientation);
    models.at(_type)->setSize(_size);
    models.at(_type)->draw(shaders);
}

void scene::AObject::setPosition(glm::vec3 position) {
    _position = position;
}

void scene::AObject::setOrientation(glm::vec3 orientation) {
    _orientation = orientation;
}

void scene::AObject::setSize(glm::vec3 size) {
    _size = size;
}

void scene::AObject::setOffset(glm::vec3 offset) {
    _offset = offset;
}

scene::ModelType scene::AObject::getType() const {
    return _type;
}
