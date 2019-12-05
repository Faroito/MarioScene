//
// Created by Timothée Couble on 17/10/2019.
//

#include "Window.hpp"

gl_wrapper::IApp *gl_wrapper::CallbackInterface::app;

gl_wrapper::Window::~Window() {
    glfwDestroyWindow(_window);
}

void gl_wrapper::Window::create(IApp *app, int width, int height, const std::string &name) {
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

    glfwSetKeyCallback(_window, gl_wrapper::CallbackInterface::OnKeyDown);
    glfwSetCursorPosCallback(_window, gl_wrapper::CallbackInterface::OnMouseMove);
    glfwSetMouseButtonCallback(_window, gl_wrapper::CallbackInterface::OnMouseDown);
    glfwSetScrollCallback(_window, gl_wrapper::CallbackInterface::OnMouseScroll);

    std::cout << "GLFW window created." << std::endl;
}

void gl_wrapper::Window::setViewport() {
    glfwGetFramebufferSize(_window, &_width, &_height);
    glViewport(0, 0, _width, _height);
}

bool gl_wrapper::Window::shouldClose() {
    return (bool) glfwWindowShouldClose(_window);
}

void gl_wrapper::Window::swapBuffers() {
    glfwSwapBuffers(_window);
}

void gl_wrapper::Window::setClose(bool close) {
    glfwSetWindowShouldClose(_window, close);
}

int gl_wrapper::Window::getWidth() const {
    return _width;
}

int gl_wrapper::Window::getHeight() const {
    return _height;
}

float gl_wrapper::Window::getRatio() const {
    return (float) _width / (float) _height;
}