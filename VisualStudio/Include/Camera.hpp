//
// Created by Timothée Couble on 19/10/2019.
//

#ifndef CAMERA_HPP
# define CAMERA_HPP

#include <iostream>
#include <memory>

#include "glm/glm.hpp"
#include "glm/gtc/matrix_transform.hpp"
#include "glm/gtc/type_ptr.hpp"

#include "Lib.hpp"
#include "Window.hpp"

namespace scene {

    class Camera {
    public:
        Camera();

        const glm::vec3 &getCameraPosition() const;
        glm::mat4 getViewMatrix() const;
        glm::mat4 getProjectionMatrix(gl_wrapper::Window &window) const;

        void zoom(double yOffset);

        void moveForward();
        void moveBackward();
        void moveUp();
        void moveDown();
        void moveLeft();
        void moveRight();
        void rotateLeft();
        void rotateRight();

    private:
        void updateCamerasVectors();

    private:
        float _fov = 45.0f;

        glm::vec3 _cameraPos = glm::vec3(6.0f, 4.0f, 12.0f);
        glm::vec3 _cameraFront = glm::vec3(0.0f, 0.0f, -1.0f);
        glm::vec3 _cameraRight = glm::vec3(0.0f, 0.0f, 0.0f);
        glm::vec3 _cameraUp = glm::vec3(0.0f, 0.0f, 0.0f);
        const glm::vec3 _worldUp = glm::vec3(0.0f, 1.0f, 0.0f);

        const float _cameraSpeed = 0.3f;
    };

    typedef std::unique_ptr<Camera> Camera_ptr_t;

}

#endif /* !CAMERA_HPP */
