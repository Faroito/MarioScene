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
            gl_wrapper::Mesh *mesh;
        };

    public:
        explicit Model(std::string &objPath);

        void draw(gl_wrapper::Shader *shader);

    private:
        int setMaterialProperties(gl_wrapper::Shader *shader, const std::string &materialName);

    private:
        std::vector<MeshMapping> _meshList;
        loader::Materials_t _materialList;
    };

}

#endif /* !MODEL_HPP */
