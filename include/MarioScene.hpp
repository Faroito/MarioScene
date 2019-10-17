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

class MarioScene : public glew_wrapper::App {
public:
    MarioScene();

    void init();

    void onDraw() override;

private:
    glew_wrapper::Shader *_shader;
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

};

#endif /* !MARIO_SCENE_HPP */
