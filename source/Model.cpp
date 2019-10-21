//
// Created by Timothée Couble on 20/10/2019.
//

#include "Model.hpp"

scene::Model::Model(const std::string &objPath) {
    auto objModel = loader::OBJLoader(objPath).load();

    const std::string &mtlFileName = objModel.getMtlFileName();
    std::size_t pos = objPath.find_last_of("/\\");
    const std::string path = objPath.substr(0, pos + 1);
    auto mtlMaterial = loader::MTLLoader(path + mtlFileName).load();

    _materialList = mtlMaterial.getMaterialList();

    for (unsigned int i = 0; i < objModel.size(); i++) {
        const std::string &materialName = objModel.getMaterialName(i);
        if (mtlMaterial.hasTextures(materialName)) {
            _meshList.push_back({objModel.getGroupsName(i), materialName,
                                 gl_wrapper::Mesh(objModel.getVertices(i), objModel.getIndices(i),
                                         mtlMaterial.getTextures(materialName))});
        } else {
            _meshList.push_back({objModel.getGroupsName(i), materialName,
                                 gl_wrapper::Mesh(objModel.getVertices(i), objModel.getIndices(i))});
        }
    }
}

scene::Model::Model(scene::Model &&other) noexcept : _meshList(std::move(other._meshList)),
    _materialList(std::move(other._materialList)) {}

scene::Model::~Model() {
    for (auto &it : _meshList)
        it.mesh.clearBuffers();
}

void scene::Model::setPosition(glm::vec3 position) {
    _position = position;
}

void scene::Model::setOrientation(glm::vec3 orientation) {
    _orientation = orientation;
}

void scene::Model::setSize(glm::vec3 size) {
    _size = size;
}

void scene::Model::draw(const gl_wrapper::Shaders_t &shaders) {
    auto model = getModelMatrix();
    auto inverse_model = glm::transpose(glm::inverse(model));
    for (auto &shader : shaders) {
        if (shader->getType() == gl_wrapper::ShaderType::LIGHT)
            continue;
        shader->bind();
        shader->setUniformMatrix4("model_matrix", model);
        shader->setUniformMatrix4("inverse_model_matrix", inverse_model);
        gl_wrapper::Shader::unBind();
    }
    for (auto &mesh : _meshList) {
        for (auto &shader : shaders) {
            if (shader->getType() != _materialList[mesh.material].type)
                continue;
            shader->bind();
            int error = setMaterialProperties(shader, mesh.material);
            if (error == -1)
                std::cerr << "Material " << mesh.material << " not found for " << mesh.name << std::endl;
            mesh.mesh.draw(shader);
            gl_wrapper::Shader::unBind();
        }
    }
}

glm::mat4 scene::Model::getModelMatrix() {
    glm::mat4 translate = glm::translate(glm::mat4(1.0f), _position);
    glm::mat4 rotate = glm::rotate(glm::mat4(1.0f), glm::radians(_orientation.x), glm::vec3(1.f, 0.f, 0.f));
    rotate = glm::rotate(rotate, glm::radians(_orientation.y), glm::vec3(0.f, 1.f, 0.f));
    rotate = glm::rotate(rotate, glm::radians(_orientation.z), glm::vec3(0.f, 0.f, 1.f));
    glm::mat4 scale = glm::scale(glm::mat4(1.0f), _size);
    return translate * rotate * scale;
}

int scene::Model::setMaterialProperties(const gl_wrapper::Shader_ptr_t &shader, const std::string &materialName) {
    if (_materialList.find(materialName) == _materialList.end())
        return -1;
    loader::Material &material = _materialList[materialName];
    shader->setUniformVector3("material.ambient",  material.ambient);
    if (material.type == gl_wrapper::ShaderType::MODEL)
        shader->setUniformVector3("material.diffuse", material.diffuse);
    shader->setUniformVector3("material.specular", material.specular);
    shader->setUniformFloat("material.shininess", material.shininess);
    return 0;
}
