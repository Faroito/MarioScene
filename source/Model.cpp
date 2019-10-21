//
// Created by Timothée Couble on 20/10/2019.
//

#include "Model.hpp"

scene::Model::Model(const std::string &objPath, gl_wrapper::ShaderType shaderType)
    : _shaderType(shaderType) {
    auto objModel = loader::OBJLoader(objPath).load();

    for (unsigned int i = 0; i < objModel.size(); i++) {
        _meshList.push_back({
            objModel.getGroupsName(i), objModel.getMaterialName(i),
            gl_wrapper::Mesh(objModel.getVertices(i), objModel.getIndices(i))
        });
    }

    const std::string &mtlFileName = objModel.getMtlFileName();
    std::size_t pos = objPath.find_last_of("/\\");
    const std::string mtlPath = objPath.substr(0, pos + 1) + mtlFileName;
    auto mtlMaterial = loader::MTLLoader(mtlPath).load();

    _materialList = mtlMaterial.getMaterialList();
}

scene::Model::Model(scene::Model &&other) noexcept : _shaderType(other._shaderType),
    _meshList(std::move(other._meshList)), _materialList(std::move(other._materialList)) {}

scene::Model::~Model() {
    for (auto &it : _meshList)
        it.mesh.clearBuffers();
}

void scene::Model::draw(const gl_wrapper::Shader_ptr_t &shader) {
    for (auto &it : _meshList) {
        int error = setMaterialProperties(shader, it.material);
        if (error == -1)
            std::cerr << "Material " << it.material << " not found for " << it.name << std::endl;
        it.mesh.draw(shader);
    }
}

int scene::Model::setMaterialProperties(const gl_wrapper::Shader_ptr_t &shader, const std::string &materialName) {
    if (_materialList.find(materialName) == _materialList.end())
        return -1;
    loader::Material &material = _materialList[materialName];
    shader->setUniformVector3("material.ambient",  material.ambient);
    shader->setUniformVector3("material.diffuse", material.diffuse);
    shader->setUniformVector3("material.specular", material.specular);
    shader->setUniformFloat("material.shininess", material.shininess);
    return 0;
}
