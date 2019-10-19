//
// Created by Timothée Couble on 19/10/2019.
//

#include "Camera.hpp"

void scene::Camera::setMousePosition(float x, float y) {

}

glm::mat4 scene::Camera::getViewMatrix() {
    updateCamerasVectors();
    return glm::lookAt(_cameraPos, _cameraPos + _cameraFront, _cameraUp);
}

void scene::Camera::updateCamerasVectors() {
    _cameraRight = glm::normalize(glm::cross(_cameraFront, _worldUp));
    _cameraUp = glm::normalize(glm::cross(_cameraRight, _cameraFront));
}

void scene::Camera::moveForward() {
    _cameraPos += _cameraSpeed * _cameraFront;
}

void scene::Camera::moveBackward() {
    _cameraPos -= _cameraSpeed * _cameraFront;
}

void scene::Camera::moveUp() {
    _cameraPos += _cameraUp * _cameraSpeed;
}

void scene::Camera::moveDown() {
    _cameraPos -= _cameraUp * _cameraSpeed;
}

void scene::Camera::moveLeft() {
    _cameraPos -= _cameraRight * _cameraSpeed;
}

void scene::Camera::moveRight() {
    _cameraPos += _cameraRight * _cameraSpeed;
}

void scene::Camera::rotateLeft() {
    _cameraFront = glm::angleAxis(_cameraSpeed / 6, _cameraUp) * _cameraFront;
}

void scene::Camera::rotateRight() {
    _cameraFront = glm::angleAxis(-_cameraSpeed / 6, _cameraUp) * _cameraFront;
}
