//
// Created by Timothée Couble on 02/11/2019.
//

#include "AObject.hpp"

scene::AObject::AObject(ModelType type, unsigned int id) : _type(type), _id(id) {
}

scene::AObject::AObject(const scene::AObject &other, unsigned int id) : _type(other._type), _id(id),
    _orientation(other._orientation), _offset(other._offset), _size(other._size) {}

void scene::AObject::init() {}

void scene::AObject::draw(const scene::Models_t &models, const gl_wrapper::Shaders_t &shaders,
                          const std::vector<std::unique_ptr<AObject>> &objects) {
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

void scene::AObject::setShape(glm::vec3 shape) {
    _shape = shape;
}

void scene::AObject::setOffset(glm::vec3 offset) {
    _offset = offset;
}

unsigned int scene::AObject::getId() const {
    return _id;
}

scene::ModelType scene::AObject::getType() const {
    return _type;
}

glm::vec3 scene::AObject::getPosition() const {
    return _position + _offset;
}

bool scene::AObject::isColliding(glm::vec3 position, glm::vec3 shape) const {
    const glm::vec3 margin = glm::vec3(0.1f, 0.1f, 0.1f);
    glm::vec3 aMin = _position + _offset - margin;
    glm::vec3 aMax = _position + _offset + _shape + margin;
    glm::vec3 bMin = position - margin;
    glm::vec3 bMax = position + shape + margin;
    return (aMin.x <= bMax.x && aMax.x >= bMin.x) &&
           (aMin.y <= bMax.y && aMax.y >= bMin.y) &&
           (aMin.z <= bMax.z && aMax.z >= bMin.z);
}
