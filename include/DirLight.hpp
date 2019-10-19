//
// Created by Timothée Couble on 19/10/2019.
//

#ifndef DIR_LIGHT_HPP
# define DIR_LIGHT_HPP

#include <iostream>

#include "glm/glm.hpp"
#include "glm/gtc/matrix_transform.hpp"

#include "Light.hpp"

namespace scene {

    class DirLight : public Light {
    public:
        explicit DirLight(const glm::vec3 &direction);

        void setDirection(const glm::vec3 &direction);
        const glm::vec3 &getDirection() const;

    private:
        glm::vec3 _direction;
    };
}

#endif /* !DIR_LIGHT_HPP */
