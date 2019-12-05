//
// Created by Timothée Couble on 17/10/2019.
//

#ifndef IAPP_HPP
# define IAPP_HPP

namespace gl_wrapper {

    class IApp {
    public:
        virtual void onMouseMove(double x, double y) = 0;
        virtual void onMouseDown(int button, int action) = 0;
        virtual void onMouseScroll(double x, double y) = 0;
        virtual void onKeyDown(int key, int action) = 0;

    };
}

#endif /* !IAPP_HPP */
