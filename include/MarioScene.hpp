//
// Created by Timothée Couble on 17/10/2019.
//

#ifndef MARIO_SCENE_HPP
# define MARIO_SCENE_HPP

#include <iostream>
#include <string>
#include <vector>

# define GLM_FORCE_RADIANS
#include "glm/glm.hpp"
#include "glm/gtc/matrix_transform.hpp"
#include "glm/gtc/type_ptr.hpp"

#include "App.hpp"
#include "Macros.hpp"
#include "Mesh.hpp"
#include "Shader.hpp"
#include "Misc.hpp"

namespace scene {

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
        gl_wrapper::Mesh *_mesh;
        GLint _modelID = 0;
        GLint _viewID = 0;
        GLint _projectionID = 0;
        int _keyCode = 0;
        glm::vec3 _eyePos = glm::vec3(0.0f, 0.0f, 5.0f);
        glm::vec3 _forwardDir = glm::vec3(0.0f, 0.0f, -1.0f);
        const glm::vec3 _upDir = glm::vec3(0.0f, 1.0f, 0.0f);
    };
}
#endif /* !MARIO_SCENE_HPP */
