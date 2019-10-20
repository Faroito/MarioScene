//
// Created by Timothée Couble on 17/10/2019.
//

#ifndef WINDOW_HPP
# define WINDOW_HPP

#include <iostream>

#include "IApp.hpp"
#include "Lib.hpp"

namespace gl_wrapper {

    struct CallbackInterface {
        static IApp *app;

        static void OnKeyDown(GLFWwindow* window, int key, int scancode, int action, int mods) {
            app->onKeyDown(key, action);
        }

        static void OnMouseMove(GLFWwindow* window, double x, double y) {
            app->onMouseMove(x, y);
        }

        static void OnMouseDown(GLFWwindow* window, int button, int action, int mods) {
            app->onMouseDown(button, action);
        }

        static void OnMouseScroll(GLFWwindow* window, double x, double y) {
            app->onMouseScroll(x, y);
        }
    };

    class Window {
    public:
        Window() = default;
        ~Window();

        void create(IApp *app, int width, int height, const std::string &name);

        void setViewport();
        bool shouldClose();

        void swapBuffers();

        void setClose(bool close);
        int getWidth() const;
        int getHeight() const;
        float getRatio() const;

    private:
        GLFWwindow *_window;
        CallbackInterface _interface;
        int _width;
        int _height;
    };

}

#endif /* !WINDOW_HPP */
