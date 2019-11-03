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
        Creature(ModelType type, unsigned int id);
        Creature(const AObject& other, unsigned int id);
        ~Creature() override;

        void init() override;
        void draw(const scene::Models_t &models, const gl_wrapper::Shaders_t &shaders,
                  const std::vector<std::unique_ptr<AObject>> &objects) override;

    protected:
        virtual void move(const std::vector<std::unique_ptr<AObject>> &objects);
        virtual void orient();

    private:
        bool _goRight = true;
        double _speed = 1.8f;
        double _lastFrame = 0.0f;
        double _lastCollision = 0.0f;
        glm::vec3 _baseOrientation = glm::vec3(0.0f, 0.0f, 0.0f);
        glm::vec3 _oldPosition = glm::vec3(0.0f, 0.0f, 0.0f);
    };

}

#endif /* !CREATURE_HPP */
