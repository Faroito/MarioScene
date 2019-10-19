//
// Created by Timothée Couble on 19/10/2019.
//

#ifndef CAMERA_HPP
# define CAMERA_HPP

#include <iostream>

#include "glm/glm.hpp"
#include "glm/gtc/matrix_transform.hpp"
#include "glm/gtc/type_ptr.hpp"

#include "Lib.hpp"

namespace scene {

    class Camera {
    public:
        Camera() = default;

        void setMousePosition(float x, float y);
        glm::mat4 getViewMatrix();

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
        glm::vec3 _cameraPos = glm::vec3(0.0f, 0.0f, 6.0f);
        glm::vec3 _cameraFront = glm::vec3(0.0f, 0.0f, -1.0f);
        glm::vec3 _cameraRight = glm::vec3(0.0f, 0.0f, 0.0f);
        glm::vec3 _cameraUp = glm::vec3(0.0f, 0.0f, 0.0f);
        const glm::vec3 _worldUp = glm::vec3(0.0f, 1.0f, 0.0f);

        const float _cameraSpeed = 0.08f;

        float _xPos = 0;
        float _yPos = 0;
    };

}

#endif /* !CAMERA_HPP */
