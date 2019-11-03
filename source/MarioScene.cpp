//
// Created by Timothée Couble on 17/10/2019.
//

#include "MarioScene.hpp"

scene::MarioScene::MarioScene() : App(960, 720, "MarioScene") {
    init();
}

void scene::MarioScene::init() {
    std::string vs_model_path = "../shader/model_vs.glsl";
    std::string fs_model_path = "../shader/model_fs.glsl";
    std::string vs_light_path = "../shader/light_vs.glsl";
    std::string fs_light_path = "../shader/light_fs.glsl";
    std::string vs_texture_path = "../shader/texture_vs.glsl";
    std::string fs_texture_path = "../shader/texture_fs.glsl";

    _shaders.push_back(std::make_unique<gl_wrapper::Shader>(
            gl_wrapper::Shader(vs_model_path, fs_model_path, gl_wrapper::ShaderType::MODEL)
    ));
    _shaders.push_back(std::make_unique<gl_wrapper::Shader>(
            gl_wrapper::Shader(vs_light_path, fs_light_path, gl_wrapper::ShaderType::LIGHT)
    ));
    _shaders.push_back(std::make_unique<gl_wrapper::Shader>(
            gl_wrapper::Shader(vs_texture_path, fs_texture_path, gl_wrapper::ShaderType::TEXTURE_DIFFUSE)
    ));

    loader::ConfigLoader config("../config.txt");
    config.load();

    auto objPaths = config.getPath();
    for (auto &it: objPaths) {
        _models.insert({
            it.first, std::make_unique<scene::Model>(scene::Model(it.second))
        });
    }
    std::move(begin(config.getObjects()), end(config.getObjects()), std::back_inserter(_objects));

    for (auto &it: _objects)
        it->init();

    std::string objPath = "../resource/lamp.obj";
    _lamp = std::make_unique<scene::Lamp>(scene::Lamp(objPath));

    _dirLight.setAmbient(glm::vec3(0.3f, 0.3f, 0.1f));
    _dirLight.setShader(_shaders);

    _pointLight.setAmbient(glm::vec3(0.96f, 0.85f, 0.05f));
    _pointLight.setDistance(2);
    _pointLight.setShader(_shaders);
}

void scene::MarioScene::onDraw() {
    this->checkKey();

    // _pointLight.setPosition(glm::vec3(cos(aTime) * 3.0f, sin(aTime / 2.0f), sin(aTime) * 2.0f));
    _pointLight.setPosition(glm::vec3(9.3f, 4.3f, 0.0f));
    _pointLight.setShader(_shaders);

    for (auto &shader : _shaders) {
        shader->bind();
        shader->setUniformMatrix4("view_matrix", _camera->getViewMatrix());
        shader->setUniformMatrix4("proj_matrix", _camera->getProjectionMatrix(getWindow()));
        if (shader->getType() != gl_wrapper::ShaderType::LIGHT)
            shader->setUniformVector3("viewPos", _camera->getCameraPosition());
        gl_wrapper::Shader::unBind();
    }

    _lamp->syncLight(_pointLight);
    _lamp->setSize(glm::vec3(0.3f));
    _lamp->draw(_shaders);

    for (auto &object : _objects)
        object->draw(_models, _shaders, _objects);
}

void scene::MarioScene::checkKey() {
    for (const auto &it : _keyMap) {
        if (_keyCode[it.first])
            (_camera.get()->*it.second)();
    }
    if (_keyCode[GLFW_KEY_ESCAPE])
        getWindow().setClose(true);
    if (_keyCode[GLFW_KEY_SPACE] && _pressed) {
        if (_mode == GL_FILL)
            _mode = GL_LINE;
        else
            _mode = GL_FILL;
        glPolygonMode(GL_FRONT_AND_BACK, _mode);
        _pressed = false;
    }
}

void scene::MarioScene::onMouseMove(double x, double y) {
    // std::cout << x << " " << y << std::endl;
}

void scene::MarioScene::onMouseDown(int button, int action) {
    if (action == GLFW_PRESS)
        std::cout << "Clicked on: " << button << std::endl;
}

void scene::MarioScene::onMouseScroll(double x, double y) {
    _camera->zoom(y);
}

void scene::MarioScene::onKeyDown(int key, int action) {
    if (action == GLFW_PRESS) {
        _pressed = true;
        _keyCode[key] = true;
    } if (action == GLFW_RELEASE)
        _keyCode[key] = false;
}
