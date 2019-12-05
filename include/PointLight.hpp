//
// Created by Timothée Couble on 19/10/2019.
//

#ifndef POINT_LIGHT_HPP
# define POINT_LIGHT_HPP

#include <iostream>
#include <map>

#include "glm/glm.hpp"
#include "glm/gtc/matrix_transform.hpp"

#include "ALight.hpp"

namespace scene {

    struct LightDistance {
        const float constant;
        const float linear;
        const float quadratic;
    };

    class PointLight : public ALight {

        enum AttenuationType {
            CONSTANT,
            LINEAR,
            QUADRATIC
        };

    public:
        explicit PointLight(const glm::vec3 &position, unsigned int distance = 20,
                unsigned int nb = 0);

        void setDistance(unsigned int distance);
        void setPosition(const glm::vec3 &position);
        const glm::vec3 &getPosition() const;

        void setShader(const gl_wrapper::Shaders_t &shaders) const;

    private:
        float readDistanceMap(AttenuationType type) const;

    private:
        glm::vec3 _position;
        unsigned int _distance;
        const std::map<unsigned int, LightDistance> _distanceMap = {
                {7, {1.0f, 0.7f, 1.8f}},
                {13, {1.0f, 0.35f, 0.44f}},
                {20, {1.0f, 0.22f, 0.20f}},
                {32, {1.0f, 0.14f, 0.07f}},
                {50, {1.0f, 0.09f, 0.032f}},
                {65, {1.0f, 0.07f, 0.017f}},
                {100, {1.0f, 0.045f, 0.0075f}},
                {160, {1.0f, 0.027f, 0.0028f}},
                {200, {1.0f, 0.022f, 0.0019f}},
                {325, {1.0f, 0.014f, 0.0007f}},
                {600, {1.0f, 0.007f, 0.0002f}},
                {3250, {1.0f, 0.0014f, 0.000007f}}
        };
    };
}

#endif /* !POINT_LIGHT_HPP */
