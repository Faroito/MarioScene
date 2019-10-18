//
// Created by Timothée Couble on 17/10/2019.
//

#ifndef MARIO_SCENE_HPP
# define MARIO_SCENE_HPP

#include <vector>

# define GLM_FORCE_RADIANS
#include "glm/glm.hpp"                    //<-- a nifty math library
#include "glm/gtc/matrix_transform.hpp"
#include "glm/gtc/type_ptr.hpp"

#include "App.hpp"
#include "Macros.hpp"
#include "Shader.hpp"
#include "Misc.hpp"

class MarioScene : public gl_wrapper::App {
public:
    MarioScene();

    void init();

    void onDraw() override;
    void onMouseMove(double x, double y) override;
    void onMouseDown(int button, int action) override;
    void onKeyDown(int key, int action) override;

private:
    bool checkKey();

private:
    gl_wrapper::Shader *_shader;
    vector<Vertex> _triangle = {
            {glm::vec2(-1, -0.5), glm::vec4(1, 0, 0, 1)},
            {glm::vec2(0, 1), glm::vec4(0, 1, 0, 1)},
            {glm::vec2(1, -.5), glm::vec4(0, 0, 1, 1)}
    };
    GLuint _positionID;
    GLuint _colorID;
    GLuint _bufferID;
    GLuint _arrayID;
    GLuint _modelID, _viewID, _projectionID;
    int _keyCode;
    glm::vec3 _eyePos;
    glm::vec3 _forwardDir = glm::vec3(0.0f, 0.0f, -1.0f);
    const glm::vec3 _upDir = glm::vec3(0.0f, 1.0f, 0.0f);
};

#endif /* !MARIO_SCENE_HPP */
