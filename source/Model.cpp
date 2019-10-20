//
// Created by Timothée Couble on 20/10/2019.
//

#include "Model.hpp"

scene::Model::Model(std::string &path) {
    auto objModel = loader::OBJLoader(path);

    const std::string &mtlFileName = objModel.getMtlFileName();
    const auto &materialNameList = objModel.getMaterialNameList();

    for (size_t i = 0; i < objModel.size(); i++) {
        _meshList.emplace(objModel.getGroupsName(i) + " " + std::to_string(i),
                new gl_wrapper::Mesh(objModel.getVertices(i), objModel.getIndices(i)));
    }
}

void scene::Model::draw(gl_wrapper::Shader *shader) {
    for (auto &it : _meshList) {
        // std::cout << it.first << std::endl;
        it.second->draw(shader);
    }
}
