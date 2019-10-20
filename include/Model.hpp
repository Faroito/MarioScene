//
// Created by Timothée Couble on 20/10/2019.
//

#ifndef MODEL_HPP
# define MODEL_HPP

#include <iostream>
#include <string>
#include <vector>
#include <unordered_map>

#include "glm/glm.hpp"

#include "Mesh.hpp"
#include "Misc.hpp"
#include "OBJLoader.hpp"
#include "Shader.hpp"

namespace scene {

    class Model {
    public:
        explicit Model(std::string &path);

        void draw(gl_wrapper::Shader *shader);

    private:
        std::unordered_map<std::string, gl_wrapper::Mesh *> _meshList;
    };

}

#endif /* MODEL_HPP */
