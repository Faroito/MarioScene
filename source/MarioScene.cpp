//
// Created by Timothée Couble on 17/10/2019.
//

#include "MarioScene.hpp"

scene::MarioScene::MarioScene() : App(640, 480, "MarioScene") {
    init();
    _eyePos = glm::vec3(0.0f, 0.0f, 5.0f);
}

void scene::MarioScene::init() {
    std::string vert = readShader("../shader/vs_model.glsl");
    std::string frag = readShader("../shader/fs_model.glsl");

    _shader = new gl_wrapper::Shader(vert.c_str(), frag.c_str());

    _positionID = (GLuint) glGetAttribLocation(_shader->getId(), "position");
    _colorID = (GLuint) glGetAttribLocation(_shader->getId(), "color");
    _modelID = (GLuint) glGetUniformLocation(_shader->getId(), "model_matrix");
    _viewID = (GLuint) glGetUniformLocation(_shader->getId(), "view_matrix");
    _projectionID = (GLuint) glGetUniformLocation(_shader->getId(), "proj_matrix");

    glGenVertexArrays(1, &_vaoID);
    glGenBuffers(1, &_vboID);
    glGenBuffers(1, &_eboID);

    glBindVertexArray(_vaoID);

    glBindBuffer(GL_ARRAY_BUFFER, _vboID);
    glBufferData(GL_ARRAY_BUFFER, _triangle.size() * sizeof(VertexColor), _triangle.data(), GL_STATIC_DRAW);

    glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, _eboID);
    glBufferData(GL_ELEMENT_ARRAY_BUFFER, _indices.size() * sizeof(unsigned int), _indices.data(), GL_STATIC_DRAW);

    glEnableVertexAttribArray(_positionID);
    glEnableVertexAttribArray(_colorID);

    glVertexAttribPointer(_positionID, 3, GL_FLOAT, GL_FALSE, sizeof(VertexColor), (void *) nullptr);
    glVertexAttribPointer(_colorID, 4, GL_FLOAT, GL_FALSE, sizeof(VertexColor), (void *) (1 * sizeof(glm::vec3)));

    // glPolygonMode(GL_FRONT_AND_BACK, GL_LINE);
    glBindBuffer(GL_ARRAY_BUFFER, 0);
    glBindVertexArray(0);
}

scene::MarioScene::~MarioScene() {
    glDeleteVertexArrays(1, &_vaoID);
    glDeleteBuffers(1, &_vboID);
    glDeleteBuffers(1, &_eboID);
}

void scene::MarioScene::onDraw() {

    static float time = 0.0;
    time += 0.01;

    _shader->bind();

    glBindVertexArray(_vaoID);

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
        glDrawElements(GL_TRIANGLES, _indices.size(), GL_UNSIGNED_INT, nullptr);
    }
    glBindVertexArray(0);
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
