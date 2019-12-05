//
// Created by Timothée Couble on 21/10/2019.
//

#ifndef LAMP_HPP
# define LAMP_HPP

#include <iostream>

#include "glm/glm.hpp"

#include "Model.hpp"
#include "PointLight.hpp"

namespace scene {

    class Lamp : public Model {
    public:
        explicit Lamp(const std::string &objPath);
        Lamp(Lamp&& other) noexcept;
        ~Lamp() = default;

        void syncLight(const PointLight &light);
        void draw(const gl_wrapper::Shaders_t &shaders) override;

    private:
        glm::vec3 _ambientColor = glm::vec3(1.0f, 1.0f, 1.0f);
    };

}

#endif /* !LAMP_HPP */
