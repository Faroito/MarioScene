//
// Created by Timothée Couble on 02/11/2019.
//

#ifndef CREATURE_HPP
# define CREATURE_HPP

#define _USE_MATH_DEFINES
#include <cmath>

#include "AObject.hpp"

namespace scene {

    class Creature : public AObject {
    public:
        explicit Creature(ModelType type);
        explicit Creature(const AObject& other);
		~Creature() = default;

        void init() override;
        void draw(const scene::Models_t &models, const gl_wrapper::Shaders_t &shaders) override;

    protected:
        virtual void move();

    private:
        void orient();

    private:
        glm::vec3 _baseOrientation = glm::vec3(0.0f, 0.0f, 0.0f);
        glm::vec3 _oldPosition = glm::vec3(0.0f, 0.0f, 0.0f);
    };

}

#endif /* !CREATURE_HPP */
