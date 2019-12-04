//
// Created by Timothée Couble on 17/10/2019.
//

#include "App.hpp"

gl_wrapper::App::App(unsigned int width, unsigned int height, const std::string &name) {
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

    _window.setViewport();
    _framebuffer = new gl_wrapper::Framebuffer(_window.getWidth(), _window.getHeight());

    while (!_window.shouldClose()){
        this->App::checkKey();

        _framebuffer->bind();
        glEnable(GL_DEPTH_TEST);

        glClearColor(0.31f, 0.47f, 0.54f, 1.0f);
        glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
        _framebuffer->setViewPort();
        onDraw();

        glDisable(GL_DEPTH_TEST);
        gl_wrapper::Framebuffer::unBind();

        glClearColor(1.0f, 1.0f, 1.0f, 1.0f);
        glClear(GL_COLOR_BUFFER_BIT);
        _window.setViewport();
        _framebuffer->draw();

        glfwPollEvents();
        _window.swapBuffers();
    }
    delete _framebuffer;
}

void gl_wrapper::App::checkKey() {
    if (_keyCode[GLFW_KEY_ENTER] && _pressed) {
        _framebuffer->passToNextShader();
        _pressed = false;
    }
}

void gl_wrapper::App::onDraw() {}

void gl_wrapper::App::onMouseMove(double x, double y) {
    // std::cout << x << " " << y << std::endl;
}

void gl_wrapper::App::onMouseDown(int button, int action) {
    if (action == GLFW_PRESS)
        std::cout << "Clicked on: " << button << std::endl;
}

void gl_wrapper::App::onMouseScroll(double x, double y) {}

void gl_wrapper::App::onKeyDown(int key, int action) {
    if (action == GLFW_PRESS) {
        _pressed = true;
        _keyCode[key] = true;
    } if (action == GLFW_RELEASE)
        _keyCode[key] = false;
}


gl_wrapper::Window& gl_wrapper::App::getWindow() {
    return _window;
}