//
// Created by Timothée Couble on 17/10/2019.
//

#include "App.hpp"

gl_wrapper::App::App(int width, int height, const std::string &name) {
    if (!glfwInit())
        exit(EXIT_FAILURE);
    std::cout << "GLFW initialized." << std::endl;

    glfwSetErrorCallback(error::callbackGLFW);
    hintsGLFW();

    _window.create(this, width, height, name);

    glewExperimental = GL_TRUE;
    GLenum glewError = glewInit();
    if (glewError != GLEW_OK) {
        std::cout << "GLFW init error:" << std::endl
                  << glewGetErrorString(glewError) << std::endl;
    }

    glEnable(GL_DEPTH_TEST);
    glDepthFunc(GL_LESS);

    glEnable(GL_BLEND);
    glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);
}

void gl_wrapper::App::hintsGLFW() {
    glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3);
    glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 2);
    glfwWindowHint(GLFW_OPENGL_FORWARD_COMPAT, GL_TRUE);
    glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);
}

gl_wrapper::App::~App() {
    glfwTerminate();
}

void gl_wrapper::App::start() {
    std::cout << "Starting app..." << std::endl;

    while (!_window.shouldClose()){

        _window.setViewport();

        glClearColor(.2,.2,.4,1);
        glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

        onDraw();

        glfwPollEvents();
        _window.swapBuffers();
    }
}

void gl_wrapper::App::onDraw() {}

void gl_wrapper::App::onMouseMove(double x, double y) {}

void gl_wrapper::App::onMouseDown(int button, int action) {}

void gl_wrapper::App::onKeyDown(int key, int action) {}

gl_wrapper::Window& gl_wrapper::App::getWindow() {
    return _window;
}