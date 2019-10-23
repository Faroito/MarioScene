//
// Created by Timothée Couble on 17/10/2019.
//

#include "App.hpp"

gl_wrapper::App::App(int width, int height, const std::string &name) {
    if (!glfwInit())
        exit(EXIT_FAILURE);
    std::cout << "GLFW initialized." << std::endl;

    hintsGLFW();

    _window.create(this, width, height, name);

    glewExperimental = GL_TRUE;
    GLenum glewError = glewInit();
    if (glewError != GLEW_OK) {
        std::cout << "GLFW init error:" << std::endl
                  << glewGetErrorString(glewError) << std::endl;
    }

    glEnable(GL_CULL_FACE);
    glFrontFace(GL_CCW);
    glCullFace(GL_BACK);

    glEnable(GL_DEPTH_TEST);
    glDepthFunc(GL_LESS);

    glEnable(GL_BLEND);
    glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);
}
#if _MSC_VER
    void gl_wrapper::App::hintsGLFW() {
        glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 4);
        glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 3);
        glfwWindowHint(GLFW_OPENGL_DEBUG_CONTEXT, GL_TRUE);
        glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);
    }
#else
    void gl_wrapper::App::hintsGLFW() {
        glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 4);
        glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 1);
        glfwWindowHint(GLFW_OPENGL_DEBUG_CONTEXT, GL_TRUE);
        glfwWindowHint(GLFW_OPENGL_FORWARD_COMPAT, GL_TRUE);
        glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);
    }
#endif

gl_wrapper::App::~App() {
    glfwTerminate();
}

void gl_wrapper::App::start() {
    std::cout << "Starting app..." << std::endl;

    while (!_window.shouldClose()){

        _window.setViewport();

        glClearColor(0.31f, 0.47f, 0.54f, 1.0f);
        glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

        onDraw();

        glfwPollEvents();
        _window.swapBuffers();
    }
}

void gl_wrapper::App::onDraw() {}

void gl_wrapper::App::onMouseMove(double x, double y) {}

void gl_wrapper::App::onMouseDown(int button, int action) {}

void gl_wrapper::App::onMouseScroll(double x, double y) {}

void gl_wrapper::App::onKeyDown(int key, int action) {}

gl_wrapper::Window& gl_wrapper::App::getWindow() {
    return _window;
}