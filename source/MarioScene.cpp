//
// Created by Timothée Couble on 17/10/2019.
//

#include "MarioScene.hpp"

scene::MarioScene::MarioScene() : App(640, 480, "MarioScene") {
    init();
}

void scene::MarioScene::init() {
    std::string vs_model_path = "../shader/test_vs.glsl";
    std::string fs_model_path = "../shader/test_fs.glsl";
    std::string vs_lamp_path = "../shader/lamp_vs.glsl";
    std::string fs_lamp_path = "../shader/lamp_fs.glsl";

    _objectShader = new gl_wrapper::Shader(vs_model_path, fs_model_path);
    _lampShader = new gl_wrapper::Shader(vs_model_path, fs_lamp_path);

    auto vertex = getExampleVertex(2);
    auto indices = getExampleIndices(2);

    _objectMesh = new gl_wrapper::Mesh(vertex, indices);
    _objectMesh->setupMesh(_objectShader);

    _lampMesh = new gl_wrapper::Mesh(vertex, indices);
    _lampMesh->setupMesh(_lampShader);

    // glPolygonMode(GL_FRONT_AND_BACK, GL_LINE);
}

void scene::MarioScene::onDraw() {
    this->checkKey();
    auto view = _camera->getViewMatrix();
    auto proj = _camera->getProjectionMatrix(getWindow());

    glm::vec3 lightPos(0.0f, 0.0f, 0.0f);
    lightPos.x = cos(glfwGetTime()) * 2.0f;
    lightPos.y = sin(glfwGetTime() / 2.0f);
    lightPos.z = sin(glfwGetTime()) * 2.0f;

    _objectShader->bind();

    _objectShader->setUniformVector3("objectColor", glm::vec3(0.87f, 0.34f, 0.22f));
    _objectShader->setUniformVector3("lightColor", glm::vec3(1.0f, 1.0f, 1.0f));
    _objectShader->setUniformVector3("lightPos", lightPos);
    _objectShader->setUniformVector3("viewPos", _camera->getCameraPosition());
    _objectShader->setUniformMatrix4("view_matrix", view);
    _objectShader->setUniformMatrix4("proj_matrix", proj);

    auto rotate = glm::rotate(glm::mat4(1.0f), 45.0f, glm::vec3(0.3f, 1.0f, 0.0f));
    _objectShader->setUniformMatrix4("model_matrix", rotate);
    auto inverse_model = glm::transpose(glm::inverse(rotate));
    _objectShader->setUniformMatrix4("inverse_model_matrix", inverse_model);
    _objectMesh->draw();

    _lampShader->bind();

    auto model = glm::mat4(1.0f);
    model = glm::translate(model, lightPos);
    model = glm::scale(model, glm::vec3(0.2f));

    _lampShader->setUniformMatrix4("view_matrix", view);
    _lampShader->setUniformMatrix4("proj_matrix", proj);
    _lampShader->setUniformMatrix4("model_matrix", model);
    _lampMesh->draw();

//    for (int i = 0; i < 5; i++) {
//        glm::mat4 translate = glm::translate(glm::mat4(1.0f), glm::vec3((float) i * 1 - 2.0f, 0.0f, 0.0f));
//        glm::mat4 rotate = glm::rotate(glm::mat4(1.0f), time * (float) M_PI, glm::vec3(1, 1, 1));
//        glm::mat4 scale = glm::scale(glm::mat4(1.0f), glm::vec3(0.5f));
//        glm::mat4 model = translate * rotate * scale;
//        glUniformMatrix4fv(_modelID, 1, GL_FALSE, glm::value_ptr(model));
//        _objectMesh->draw();
//    }
    glUseProgram(0);
}

void scene::MarioScene::checkKey() {
    for (const auto &it : _keyMap) {
        if (_keyCode[it.first])
            (_camera->*it.second)();
    }
    if (_keyCode[GLFW_KEY_ESCAPE])
        getWindow().setClose(true);
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
    if (action == GLFW_PRESS)
        _keyCode[key] = true;
    if (action == GLFW_RELEASE)
        _keyCode[key] = false;
}
