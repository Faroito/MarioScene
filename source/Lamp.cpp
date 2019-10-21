//
// Created by Timothée Couble on 21/10/2019.
//

#include "Lamp.hpp"

scene::Lamp::Lamp(const std::string &objPath) : Model(objPath) {}

scene::Lamp::Lamp(scene::Lamp &&other) noexcept : Model(std::move(other)),
    _ambientColor(other._ambientColor) {}

void scene::Lamp::syncLight(const scene::PointLight &light) {
    setPosition(light.getPosition());
    _ambientColor = light.getAmbient();
}

void scene::Lamp::draw(const gl_wrapper::Shaders_t &shaders) {
    auto model = getModelMatrix();
    for (auto &shader : shaders) {
        if (shader->getType() != gl_wrapper::ShaderType::LIGHT)
            continue;
        shader->bind();
        shader->setUniformMatrix4("model_matrix", model);
        shader->setUniformVector3("ambientLightColor", _ambientColor);
        for (auto &mesh : _meshList)
            mesh.mesh.draw(shader);
        gl_wrapper::Shader::unBind();
    }
}
