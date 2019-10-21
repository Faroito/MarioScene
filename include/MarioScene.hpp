//
// Created by Timothée Couble on 17/10/2019.
//

#ifndef MARIO_SCENE_HPP
# define MARIO_SCENE_HPP

#include <iostream>
#include <string>
#include <vector>
#include <unordered_map>
#include <memory>

#include "glm/glm.hpp"
#include "glm/gtc/matrix_transform.hpp"

#include "App.hpp"
#include "Camera.hpp"
#include "DirLight.hpp"
#include "Mesh.hpp"
#include "Model.hpp"
#include "Misc.hpp"
#include "PointLight.hpp"
#include "Shader.hpp"

namespace scene {

    class MarioScene : public gl_wrapper::App {

        typedef void (scene::Camera::*change_camera_t)();

    public:
        MarioScene();

        void init();

        void onDraw() override;
        void onMouseMove(double x, double y) override;
        void onMouseDown(int button, int action) override;
        void onMouseScroll(double x, double y) override;
        void onKeyDown(int key, int action) override;

    private:
        void checkKey();

    private:
        bool _pressed = true;
        GLenum _mode = GL_FILL;
        std::unique_ptr<scene::Model> _model;
        std::unique_ptr<scene::Model> _light;
        gl_wrapper::Shader_ptr_t _modelShader;
        gl_wrapper::Shader_ptr_t _lightShader;
        Camera_ptr_t _camera = std::make_unique<Camera>(Camera());
        bool _keyCode[512] = { false };
        const std::unordered_map<int, change_camera_t> _keyMap = {
                {GLFW_KEY_W, &scene::Camera::moveForward},
                {GLFW_KEY_S, &scene::Camera::moveBackward},
                {GLFW_KEY_R, &scene::Camera::moveUp},
                {GLFW_KEY_F, &scene::Camera::moveDown},
                {GLFW_KEY_A, &scene::Camera::moveLeft},
                {GLFW_KEY_D, &scene::Camera::moveRight},
                {GLFW_KEY_Q, &scene::Camera::rotateLeft},
                {GLFW_KEY_E, &scene::Camera::rotateRight}
        };
    };
}
#endif /* !MARIO_SCENE_HPP */
