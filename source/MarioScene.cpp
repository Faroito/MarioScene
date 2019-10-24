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
    std::string objPath = "../resource/piranha_plant.obj";

    _plant = std::make_unique<scene::Model>(scene::Model(objPath));
    objPath = "../resource/goompa.obj";
    _goompa = std::make_unique<scene::Model>(scene::Model(objPath));
    objPath = "../resource/mushroom.obj";
    _mushroom = std::make_unique<scene::Model>(scene::Model(objPath));
    objPath = "../resource/block.obj";
    _block = std::make_unique<scene::Model>(scene::Model(objPath));
    objPath = "../resource/question_block.obj";
    _question_block = std::make_unique<scene::Model>(scene::Model(objPath));
    objPath = "../resource/lamp.obj";
    _lamp = std::make_unique<scene::Lamp>(scene::Lamp(objPath));

    _dirLight.setAmbient(glm::vec3(0.3f, 0.3f, 0.1f));
    _dirLight.setShader(_shaders);

    _pointLight.setAmbient(glm::vec3(0.96f, 0.85f, 0.05f));
    _pointLight.setDistance(2);
    _pointLight.setShader(_shaders);
}

void scene::MarioScene::onDraw() {
    auto aTime = (float) glfwGetTime();

    this->checkKey();

    // _pointLight.setPosition(glm::vec3(cos(aTime) * 3.0f, sin(aTime / 2.0f), sin(aTime) * 2.0f));
    _pointLight.setPosition(glm::vec3(0.1f, 3.3f, 0.0f));
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

    /* for (int i = 0; i < 5; i++) {
        _goompa->setPosition(glm::vec3((float) i * 1 - 2.0f, 0.0f, 0.0f));
        auto rotation = (aTime * 3.14159265359f) / ((float) i * 2 + 10);
        _goompa->setOrientation(glm::vec3(rotation, rotation, rotation));
        _goompa->setSize(glm::vec3(0.05f));
        _goompa->draw(_shaders);
    }*/
    _plant->setPosition(glm::vec3(2.0f, 0.0f, 0.0f));
    _plant->setOrientation(glm::vec3(0.0f, 60.0f, 0.0f));
    _plant->setSize(glm::vec3(0.3f));
    _plant->draw(_shaders);
    _goompa->setPosition(glm::vec3(-2.0f, 0.0f, 0.0f));
    _goompa->setOrientation(glm::vec3(0.0f, 180.0f, 0.0f));
    _goompa->setSize(glm::vec3(0.1f));
    _goompa->draw(_shaders);
    _mushroom->setPosition(glm::vec3(-2.40f, 5.50f, 0));
    _mushroom->setOrientation(glm::vec3(0.0f, 90.0f, 0.0f));
    _mushroom->setSize(glm::vec3(0.1f));
    _mushroom->draw(_shaders);
    _block->setSize(glm::vec3(0.1f));
    _block->setPosition(glm::vec3(-1.20f, 4.5f, 0));
    _block->draw(_shaders);
    _block->setPosition(glm::vec3(-3.60f, 4.5f, 0));
    _block->draw(_shaders);
    _question_block->setSize(glm::vec3(0.1f));
    _question_block->setPosition(glm::vec3(-2.40f, 4.34f, 0));
    _question_block->draw(_shaders);
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
