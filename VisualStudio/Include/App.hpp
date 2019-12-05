//
// Created by Timothée Couble on 17/10/2019.
//

#ifndef APPLICATION_HPP
# define APPLICATION_HPP

#include <iostream>

#include "IApp.hpp"
#include "Lib.hpp"
#include "Window.hpp"
#include "Framebuffer.hpp"

namespace gl_wrapper {

    class App : public IApp {
    public:
        explicit App(unsigned int width, unsigned int height, const std::string &name);
        ~App();

        void start();

        virtual void onDraw();
        void onMouseMove(double x, double y) override;
        void onMouseDown(int button, int action) override;
        void onMouseScroll(double x, double y) override;
        void onKeyDown(int key, int action) override;

    protected:
        Window &getWindow();
        virtual void checkKey();

    private:
        void hintsGLFW();

    protected:
        bool _pressed = true;
        bool _keyCode[512] = { false };

    private:
        Window _window;
        Framebuffer *_framebuffer;
    };

}

#endif /* !APPLICATION_HPP*/
