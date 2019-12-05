//
// Created by Timothée Couble on 19/10/2019.
//

#include "PointLight.hpp"

scene::PointLight::PointLight(const glm::vec3 &position, const unsigned int distance,
        const unsigned int nb)
    : _position(position), _distance(distance), ALight("lights[" + std::to_string(nb) + "]") {}

void scene::PointLight::setDistance(const unsigned int distance) {
    _distance = distance;
}

void scene::PointLight::setPosition(const glm::vec3 &position) {
    _position = position;
}

const glm::vec3 &scene::PointLight::getPosition() const {
    return _position;
}

void scene::PointLight::setShader(const gl_wrapper::Shaders_t &shaders) const {
    for (auto &shader : shaders) {
        if (shader->getType() != gl_wrapper::ShaderType::LIGHT) {
            shader->bind();
            ALight::setShader(shader);
            shader->setUniformVector3(getUniformName("position").c_str(), _position);
            shader->setUniformFloat(getUniformName("constant").c_str(), readDistanceMap(CONSTANT));
            shader->setUniformFloat(getUniformName("linear").c_str(), readDistanceMap(LINEAR));
            shader->setUniformFloat(getUniformName("quadratic").c_str(), readDistanceMap(QUADRATIC));
            gl_wrapper::Shader::unBind();
        }
    }
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
