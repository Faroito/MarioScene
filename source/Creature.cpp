//
// Created by Timothée Couble on 02/11/2019.
//

#include "Creature.hpp"

scene::Creature::Creature(ModelType type, unsigned int id) : AObject(type, id) {}

scene::Creature::Creature(const scene::AObject &other, unsigned int id) : AObject(other, id) {}

scene::Creature::~Creature() {
    AObject::~AObject();
}

void scene::Creature::init() {
    std::random_device rd;
    std::mt19937 gen(rd());
    std::uniform_real_distribution<> dis(0.0, 0.6);
    _speed = 1.6 + dis(gen);

    _offset += _position;
    _baseOrientation = _orientation;
    _position = glm::vec3(0.0f);
    _lastFrame = glfwGetTime();
}

void scene::Creature::draw(const scene::Models_t &models, const gl_wrapper::Shaders_t &shaders,
                           const std::vector<std::unique_ptr<AObject>> &objects) {
    move(objects);
    orient();
    AObject::draw(models, shaders, objects);
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

void scene::Creature::move(const std::vector<std::unique_ptr<AObject>> &objects) {
    auto aTime = glfwGetTime();
    auto nextPosition = _offset + _position;

    for (auto &it : objects) {
        if (it->getId() == _id)
            continue;
        if (it->isColliding(nextPosition, _shape)) {
            _goRight = !(nextPosition.x < it->getPosition().x);
        }
    }
    if (_goRight)
        _position.x += _speed * (aTime - _lastFrame);
    else
        _position.x -= _speed * (aTime - _lastFrame);
    _lastFrame = aTime;

}
