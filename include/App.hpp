//
// Created by Timothée Couble on 17/10/2019.
//

#ifndef APPLICATION_HPP
# define APPLICATION_HPP

#include "IApp.hpp"
#include "Error.hpp"
#include "Lib.hpp"
#include "Window.hpp"

namespace gl_wrapper {

    class App : public IApp {
    public:
        explicit App(int width, int height, const std::string &name);
        ~App();

        void start();

        virtual void onDraw();
        void onMouseMove(double x, double y) override;
        void onMouseDown(int button, int action) override;
        void onKeyDown(int key, int action) override;

    protected:
        Window &getWindow();

    private:
        void hintsGLFW();

    private:
        Window _window;
    };

}

#endif /* !APPLICATION_HPP*/
