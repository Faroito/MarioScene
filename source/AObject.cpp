//
// Created by Timothée Couble on 02/11/2019.
//

#include "AObject.hpp"

scene::AObject::AObject(ModelType type) : _type(type) {}

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

void scene::AObject::draw(const scene::Models_t &models, const gl_wrapper::Shaders_t &shaders) {
    models.at(_type)->setPosition(_position + _offset);
    models.at(_type)->setOrientation(_orientation);
    models.at(_type)->setSize(_size);
    models.at(_type)->draw(shaders);
}

scene::ModelType scene::AObject::getType() const {
    return _type;
}

void scene::AObject::dump() {
    std::cout << int(_type) << std::endl;
    std::cout << "\t" << _position.x << " " << _position.y << " " << _position.z << std::endl;
    std::cout << "\t" << _orientation.x << " " << _orientation.y << " " << _orientation.z << std::endl;
    std::cout << "\t" << _size.x << " " << _size.y << " " << _size.z << std::endl;
}
