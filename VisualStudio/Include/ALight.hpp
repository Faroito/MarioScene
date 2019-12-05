//
// Created by Timothée Couble on 19/10/2019.
//

#ifndef LIGHT_HPP
# define LIGHT_HPP

#include <iostream>

#include "glm/glm.hpp"
#include "glm/gtc/matrix_transform.hpp"

#include "Shader.hpp"

namespace scene {

    class ALight {
    public:
        explicit ALight(const std::string &name);
        virtual ~ALight() = default;

        void setAmbient(const glm::vec3 &ambient);
        void setDiffuse(const glm::vec3 &diffuse);
        void setSpecular(const glm::vec3 &specular);
        const glm::vec3 &getAmbient() const;

    protected:
        void setShader(const gl_wrapper::Shader_ptr_t &shader) const;
        std::string getUniformName(const std::string &type) const;

    private:
        const std::string _name;
        glm::vec3 _ambient = glm::vec3(0.2f, 0.2f, 0.2f);
        glm::vec3 _diffuse = glm::vec3(0.5f, 0.5f, 0.5f);
        glm::vec3 _specular = glm::vec3(1.0f, 1.0f, 1.0f);
    };

}

#endif /* !LIGHT_HPP */
