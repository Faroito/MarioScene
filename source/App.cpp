//
// Created by Timothée Couble on 17/10/2019.
//

#include "App.hpp"

glew_wrapper::App::App(int width, int height, const std::string &name) {
    if (!glfwInit())
        exit(EXIT_FAILURE);
    std::cout << "GLFW initialized." << std::endl;

    _window.create(this, width, height, name);

    glewExperimental = GL_TRUE;
    GLenum glewError = glewInit();
    if (glewError != GLEW_OK) {
        std::cout << "GLFW init error:" << std::endl
                  << glewGetErrorString(glewError) << std::endl;
    }

    if (GLEW_APPLE_vertex_array_object) {
        std::cout << "genVertexArrayAPPLE supported." << std::endl;
    } else if (GLEW_ARB_vertex_array_object) {
        std::cout << "genVertexArrays supported." << std::endl;
    }

    glEnable(GL_DEPTH_TEST);
    glDepthFunc(GL_LESS);

    glEnable(GL_BLEND);
    glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);

    glLineWidth(3);
}

glew_wrapper::App::~App() {
    glfwTerminate();
}

void glew_wrapper::App::start() {
    std::cout << "Starting app..." << std::endl;

    while (!_window.shouldClose()){

        _window.setViewport();

        glClearColor(.2,.2,.4,1);
        glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

        onDraw();

        _window.swapBuffers();
        glfwPollEvents();
    }
}

void glew_wrapper::App::onDraw() {}

void glew_wrapper::App::onMouseMove(double x, double y) {}

void glew_wrapper::App::onMouseDown(int button, int action) {}

void glew_wrapper::App::onKeyDown(int key, int action) {}

glew_wrapper::Window& glew_wrapper::App::getWindow() {
    return _window;
}