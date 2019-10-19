//
// Created by Timothée Couble on 17/10/2019.
//

#ifndef MARIO_SCENE_HPP
# define MARIO_SCENE_HPP

#include <iostream>
#include <string>
#include <vector>
#include <unordered_map>
#include <cmath>

#include "glm/glm.hpp"
#include "glm/gtc/matrix_transform.hpp"

#include "App.hpp"
#include "Camera.hpp"
#include "DirLight.hpp"
#include "Mesh.hpp"
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
        gl_wrapper::Shader *_objectShader;
        gl_wrapper::Shader *_lightShader;
        gl_wrapper::Mesh *_objectMesh;
        gl_wrapper::Mesh *_lightMesh;
        scene::Camera *_camera = new scene::Camera();
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
