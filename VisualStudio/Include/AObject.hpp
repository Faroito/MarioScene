//
// Created by Timothée Couble on 02/11/2019.
//

#ifndef AOBJECT_HPP
# define AOBJECT_HPP

#include <iostream>
#include <string>
#include <vector>
#include <memory>
#include <random>

#include "Misc.hpp"
#include "Model.hpp"
#include "Shader.hpp"

namespace scene {

    class AObject {
    public:
        AObject(ModelType type, unsigned int id);
        AObject(const AObject& other, unsigned int id);
		virtual ~AObject() = default;

        virtual void init();
        virtual void draw(const scene::Models_t &models, const gl_wrapper::Shaders_t &shaders,
                const std::vector<std::unique_ptr<AObject>> &objects);

        void setPosition(glm::vec3 position);
        void setOrientation(glm::vec3 orientation);
        void setSize(glm::vec3 size);
        void setShape(glm::vec3 shape);
        void setOffset(glm::vec3 offset);

        unsigned int getId() const;
        ModelType getType() const;
        glm::vec3 getPosition() const;
        bool isColliding(glm::vec3 position, glm::vec3 shape) const;

    protected:
        const unsigned int _id = 0;
        glm::vec3 _position = glm::vec3(0.0f, 0.0f, 0.0f);
        glm::vec3 _orientation = glm::vec3(0.0f, 0.0f, 0.0f);
        glm::vec3 _offset = glm::vec3(0.0f, 0.0f, 0.0f);
        glm::vec3 _shape = glm::vec3(1.0f, 1.0f, 1.0f);

    private:
        const ModelType _type = scene::ModelType::UNKNOWN;
        glm::vec3 _size = glm::vec3(1.0f, 1.0f, 1.0f);
    };

    typedef std::unique_ptr<AObject> Objects_ptr_t;
    typedef std::vector<Objects_ptr_t> Objects_t;

}

#endif /* !AOBJECT_HPP */
