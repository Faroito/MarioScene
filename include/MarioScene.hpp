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
#include <set>

#include "glm/glm.hpp"
#include "glm/gtc/matrix_transform.hpp"

#include "App.hpp"
#include "AObject.hpp"
#include "Camera.hpp"
#include "ConfigLoader.hpp"
#include "DirLight.hpp"
#include "Lamp.hpp"
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
        void onMouseScroll(double x, double y) override;

    private:
        void checkKey() override;

    private:
        glm::vec3 old_pos= glm::vec3(0.0f, 0.0f, 0.0f);
        GLenum _mode = GL_FILL;
        scene::Models_t _models;
        scene::Objects_t _objects;
        std::unique_ptr<scene::Lamp> _lamp;
        gl_wrapper::Shaders_t _shaders;
        scene::PointLight _pointLight = scene::PointLight(glm::vec3(0, 0, 0), 50);
        scene::DirLight _dirLight = scene::DirLight(glm::vec3(0.0f, -1.0f, -1.0f));
        Camera_ptr_t _camera = std::make_unique<Camera>(Camera());
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
