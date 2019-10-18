//
// Created by Timothée Couble on 17/10/2019.
//

#include "MarioScene.hpp"

scene::MarioScene::MarioScene() : App(640, 480, "MarioScene") {
    init();
}

void scene::MarioScene::init() {
    std::string vert = readShader("../shader/vs_model.glsl");
    std::string frag = readShader("../shader/fs_model.glsl");

    _shader = new gl_wrapper::Shader(vert.c_str(), frag.c_str());

    auto vertex = getExampleVertex(1);
    auto indices = getExampleIndices(1);
    _mesh = new gl_wrapper::Mesh(vertex, indices);

    _mesh->setupMesh(_shader);

    _modelID = glGetUniformLocation(_shader->getId(), "model_matrix");
    _viewID = glGetUniformLocation(_shader->getId(), "view_matrix");
    _projectionID = glGetUniformLocation(_shader->getId(), "proj_matrix");

    // glPolygonMode(GL_FRONT_AND_BACK, GL_LINE);
}

void scene::MarioScene::onDraw() {

    static float time = 0.0;
    time += 0.01;

    _shader->bind();

    this->checkKey();
    glm::mat4 view = glm::lookAt(_eyePos, _eyePos + _forwardDir, _upDir);
    glm::mat4 proj = glm::perspective(glm::radians(45.0f), getWindow().getRatio(), 0.1f, 1000.0f);

    glUniformMatrix4fv(_viewID, 1, GL_FALSE, glm::value_ptr(view));
    glUniformMatrix4fv(_projectionID, 1, GL_FALSE, glm::value_ptr(proj));

    for (int i = 0; i < 5; i++) {
        glm::mat4 translate = glm::translate(glm::mat4(1.0f), glm::vec3((float) i * 1 - 2.0f, 0.0f, 0.0f));
        glm::mat4 rotate = glm::rotate(glm::mat4(1.0f), time * PI, glm::vec3(1, 1, 1));
        glm::mat4 scale = glm::scale(glm::mat4(1.0f), glm::vec3(0.5f));
        glm::mat4 model = translate * rotate * scale;
        glUniformMatrix4fv(_modelID, 1, GL_FALSE, glm::value_ptr(model));
        _mesh->draw();
    }
    _shader->unBind();
}

bool scene::MarioScene::checkKey() {
    if (_keyCode == -1)
        return false;
    if (_keyCode == GLFW_KEY_W)
        _eyePos += _forwardDir * .05f;
    if (_keyCode == GLFW_KEY_S)
        _eyePos -= _forwardDir * .05f;
    if (_keyCode == GLFW_KEY_A) {
        glm::quat q = glm::angleAxis(.01f, glm::vec3(0,1,0));
        _forwardDir = q * _forwardDir;
    }
    if (_keyCode == GLFW_KEY_D) {
        glm::quat q = glm::angleAxis(-.01f, glm::vec3(0,1,0));
        _forwardDir = q * _forwardDir;
    }
    if (_keyCode == GLFW_KEY_ESCAPE) {
        getWindow().setClose(true);
    }
    return true;
}

void scene::MarioScene::onMouseMove(double x, double y) {
    // std::cout << x << " " << y << std::endl;
}

void scene::MarioScene::onMouseDown(int button, int action) {
    if (action == GLFW_PRESS)
        std::cout << "Clicked on: " << button << std::endl;
}

void scene::MarioScene::onKeyDown(int key, int action) {
    if (action == GLFW_PRESS) {
        _keyCode = key;
        // std::cout << "KeyDown on: " << key << std::endl;
    }
    if (action == GLFW_RELEASE)
        _keyCode  = -1;
}
