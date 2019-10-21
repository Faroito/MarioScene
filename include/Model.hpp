//
// Created by Timothée Couble on 20/10/2019.
//

#ifndef MODEL_HPP
# define MODEL_HPP

#include <iostream>
#include <string>
#include <vector>
#include <unordered_map>
#include <algorithm>

#include "glm/glm.hpp"

#include "Mesh.hpp"
#include "Misc.hpp"
#include "MTLLoader.hpp"
#include "OBJLoader.hpp"
#include "Shader.hpp"

namespace scene {

    class Model {

        struct MeshMapping {
            const std::string name;
            const std::string material;
            gl_wrapper::Mesh mesh;
        };

    public:
        explicit Model(const std::string &objPath, bool isLamp = false);
        Model(Model&& other) noexcept;
        ~Model();

        void setPosition(glm::vec3 position);
        void setOrientation(glm::vec3 orientation);
        void setSize(glm::vec3 size);
        void draw(const gl_wrapper::Shaders_t &shaders);

    private:
        glm::mat4 getModelMatrix();
        int setMaterialProperties(const gl_wrapper::Shader_ptr_t &shader, const std::string &materialName);

    private:
        const bool _isLamp;
        glm::vec3 _position = glm::vec3(0.0f, 0.0f, 0.0f);
        glm::vec3 _orientation = glm::vec3(0.0f, 0.0f, 0.0f);
        glm::vec3 _size = glm::vec3(1.0f, 1.0f, 1.0f);
        std::vector<MeshMapping> _meshList;
        loader::Materials_t _materialList;
    };

}

#endif /* !MODEL_HPP */
