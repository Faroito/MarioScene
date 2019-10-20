//
// Created by Timothée Couble on 19/10/2019.
//

#ifndef LIGHT_HPP
# define LIGHT_HPP

#include <iostream>

#include "glm/glm.hpp"
#include "glm/gtc/matrix_transform.hpp"

namespace scene {

    class Light {
    public:
        Light() = default;
        virtual ~Light() = default;

        void setColor(const glm::vec3 &color);
        void setAmbient(const glm::vec3 &ambient);
        void setDiffuse(const glm::vec3 &diffuse);
        void setSpecular(const glm::vec3 &specular);
        const glm::vec3 &getColor() const;
        const glm::vec3 &getAmbient() const;
        const glm::vec3 &getDiffuse() const;
        const glm::vec3 &getSpecular() const;

    private:
        glm::vec3 _color = glm::vec3(1.0f, 1.0f, 1.0f);
        glm::vec3 _ambient = glm::vec3(0.2f, 0.2f, 0.2f);
        glm::vec3 _diffuse = glm::vec3(0.5f, 0.5f, 0.5f);
        glm::vec3 _specular = glm::vec3(1.0f, 1.0f, 1.0f);
    };

}

#endif /* !LIGHT_HPP */
