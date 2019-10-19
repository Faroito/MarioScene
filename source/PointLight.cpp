//
// Created by Timothée Couble on 19/10/2019.
//

#include "PointLight.hpp"

scene::PointLight::PointLight(const glm::vec3 &position, const unsigned int distance)
    : _position(position), _distance(distance), Light() {}

void scene::PointLight::setDistance(const unsigned int distance) {
    _distance = distance;
}

void scene::PointLight::setPosition(const glm::vec3 &position) {
    _position = position;
}

float scene::PointLight::getConstant() const {
    return readDistanceMap(CONSTANT);
}

float scene::PointLight::getLinear() const {
    return readDistanceMap(LINEAR);
}

float scene::PointLight::getQuadratic() const {
    return readDistanceMap(QUADRATIC);
}

const glm::vec3 &scene::PointLight::getPosition() const {
    return _position;
}

float scene::PointLight::readDistanceMap(AttenuationType type) const {
    for (const auto &it : _distanceMap) {
        if (_distance <= it.first or it.first == 3250) {
            switch (type) {
                case CONSTANT:
                    return it.second.constant;
                case LINEAR:
                    return it.second.linear;
                case QUADRATIC:
                    return it.second.quadratic;
            }
        }
    }
    return 0;
}
