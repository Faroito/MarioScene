//
// Created by Timothée Couble on 17/10/2019.
//

#include "MarioScene.hpp"

MarioScene::MarioScene() : App(640, 480, "MarioScene") {
    init();
}

void MarioScene::init() {
    std::string vert = readShader("../resource/vs_model.glsl");
    std::string frag = readShader("../resource/fs_model.glsl");

    _shader = new glew_wrapper::Shader(vert.c_str(), frag.c_str());

    _positionID = (GLuint) glGetAttribLocation(_shader->getId(), "position");
    _colorID = (GLuint) glGetAttribLocation(_shader->getId(), "color");
    _modelID = (GLuint) glGetUniformLocation(_shader->getId(), "model");
    _viewID = (GLuint) glGetUniformLocation(_shader->getId(), "view");
    _projectionID = (GLuint) glGetUniformLocation(_shader->getId(), "projection");

    GENVERTEXARRAYS(1, &_arrayID);
    BINDVERTEXARRAY(_arrayID);

    glGenBuffers(1, &_bufferID);
    glBindBuffer(GL_ARRAY_BUFFER, _bufferID);
    glBufferData(GL_ARRAY_BUFFER, 3 * sizeof(Vertex), _triangle.data(), GL_STATIC_DRAW);

    glEnableVertexAttribArray(_positionID);
    glEnableVertexAttribArray(_colorID);

    glVertexAttribPointer(_positionID, 2, GL_FLOAT, GL_FALSE, sizeof(Vertex), nullptr);
    glVertexAttribPointer(_colorID, 4, GL_FLOAT, GL_FALSE, sizeof(Vertex), (void *) sizeof(glm::vec2));

    BINDVERTEXARRAY(0);

}

void MarioScene::onDraw() {

    static float time = 0.0;
    time += 0.01;

    _shader->bind();

    BINDVERTEXARRAY(_arrayID);

    glm::vec3 cameraPosition = glm::vec3(0.0f, 0.0f, 5.0f);
    glm::vec3 cameraFront = glm::vec3(0.0f, 0.0f, -1.0f);
    glm::vec3 cameraUp = glm::vec3(0.0f, 1.0f, 0.0f);
    glm::mat4 view = glm::lookAt(cameraPosition, cameraPosition + cameraFront, cameraUp);

    glm::mat4 proj = glm::perspective(glm::radians(45.0f), getWindow().getRatio(), 0.1f, 1000.0f);

    glUniformMatrix4fv(_viewID, 1, GL_FALSE, glm::value_ptr(view));
    glUniformMatrix4fv(_projectionID, 1, GL_FALSE, glm::value_ptr(proj));

    for (int i = 0; i < 2; i++) {
        glm::mat4 translate = glm::translate(glm::mat4(1.0f), glm::vec3((float) i*2, 0.0f, 0.0f));
        glm::mat4 rotate = glm::rotate(glm::mat4(1.0f), time * PI, glm::vec3(0,1,1));
        glm::mat4 scale = glm::scale(glm::mat4(1.0f), glm::vec3(0.5f));
        glm::mat4 model = translate * rotate * scale;
        glUniformMatrix4fv(_modelID, 1, GL_FALSE, glm::value_ptr(model));
        glDrawArrays(GL_TRIANGLES, 0, 3);
    }

    BINDVERTEXARRAY(0);
    _shader->unBind();
}