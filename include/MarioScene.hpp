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
    ~MarioScene();

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
            {glm::vec3(0.5f, -0.5f, 0.5f), glm::vec4(1, 0, 0, 1)},
            {glm::vec3(0.5f, 0.5f, 0.5f), glm::vec4(0, 1, 0, 1)},
            {glm::vec3(-0.5f, 0.5f, 0.5f), glm::vec4(0, 0, 1, 1)},
            {glm::vec3(-0.5f, -0.5f, 0.5f), glm::vec4(1, 1, 0, 1)}
    };
    vector<Vertex> _cube = {
            {glm::vec3(0.5f, -0.5f, 0.5f), glm::vec4(1, 0, 0, 1)},
            {glm::vec3(0.5f, 0.5f, 0.5f), glm::vec4(0, 1, 0, 1)},
            {glm::vec3(-0.5f, 0.5f, 0.5f), glm::vec4(0, 0, 1, 1)},
            {glm::vec3(-0.5f, -0.5f, 0.5f), glm::vec4(1, 1, 0, 1)},

            {glm::vec3(0.5f, -0.5f, -0.5f), glm::vec4(0, 1, 0, 1)},
            {glm::vec3(0.5f, 0.5f, -0.5f), glm::vec4(0, 0, 1, 1)},
            {glm::vec3(-0.5f, 0.5f, -0.5f), glm::vec4(1, 0, 0, 1)},
            {glm::vec3(-0.5f, -0.5f, -0.5f), glm::vec4(0, 1, 1, 1)}
    };
    vector<unsigned int> _indices = {
            0, 1, 3, // front
            1, 2, 3,
    };
    vector<unsigned int> _indices_cube = {
            1, 0, 3, // front
            1, 2, 3,
            7, 6, 5, // back
            7, 4, 5,
            6, 7, 3, // left
            6, 2, 3,
            1, 5, 4, // right
            1, 0, 4,
            6, 5, 1, // top
            6, 2, 1,
            3, 7, 4, // bottom
            3, 0, 4
    };
    GLuint _positionID;
    GLuint _colorID;
    GLuint _vboID;
    GLuint _eboID;
    GLuint _vaoID;
    GLuint _modelID, _viewID, _projectionID;
    int _keyCode;
    glm::vec3 _eyePos;
    glm::vec3 _forwardDir = glm::vec3(0.0f, 0.0f, -1.0f);
    const glm::vec3 _upDir = glm::vec3(0.0f, 1.0f, 0.0f);
};

#endif /* !MARIO_SCENE_HPP */
