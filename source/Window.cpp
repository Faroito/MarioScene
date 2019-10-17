//
// Created by Timothée Couble on 17/10/2019.
//

#include "Window.hpp"

glew_wrapper::IApp *glew_wrapper::CallbackInterface::app;

glew_wrapper::Window::~Window() {
    glfwDestroyWindow(_window);
}

void glew_wrapper::Window::create(IApp *app, int width, int height, const std::string &name) {
    _width = width;
    _height = height;

    _interface.app = app;

    _window = glfwCreateWindow(width, height, name.c_str(), nullptr, nullptr);

    if (!_window) {
        glfwTerminate();
        exit(EXIT_FAILURE);
    }

    glfwMakeContextCurrent(_window);
    glfwSwapInterval(1);

    glfwSetKeyCallback(_window, glew_wrapper::CallbackInterface::OnKeyDown);
    glfwSetCursorPosCallback(_window, glew_wrapper::CallbackInterface::OnMouseMove);
    glfwSetMouseButtonCallback(_window, glew_wrapper::CallbackInterface::OnMouseDown);

    std::cout << "GLFW window created." << std::endl;
}

void glew_wrapper::Window::setViewport() {
    glfwGetFramebufferSize(_window, &_width, &_height);
    glViewport(0, 0, _width, _height);
}

bool glew_wrapper::Window::shouldClose() {
    return (bool) glfwWindowShouldClose(_window);
}

void glew_wrapper::Window::swapBuffers() {
    glfwSwapBuffers(_window);
}

int glew_wrapper::Window::getWidth() const {
    return _width;
}

int glew_wrapper::Window::getHeight() const {
    return _height;
}

float glew_wrapper::Window::getRatio() const {
    return (float) _width / _height;
}