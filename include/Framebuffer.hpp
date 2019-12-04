//
// Created by Timothée Couble on 04/12/2019.
//

#ifndef FRAMEBUFFER_HPP
# define FRAMEBUFFER_HPP

#include <iostream>
#include <string>
#include <memory>

#include "Mesh.hpp"
#include "Shader.hpp"
#include "Misc.hpp"

namespace gl_wrapper {

    class Framebuffer {
    public:
        Framebuffer(unsigned int width, unsigned int height);
        ~Framebuffer();

        void draw();
        void setViewPort();

        void bind();
        static void unBind();

    private:

    private:
        std::unique_ptr<Mesh> _screenMesh;
        gl_wrapper::Shaders_t _screenShaders;
        GLuint _fboID = 0;
        GLuint _rboID = 0;
        int _width;
        int _height;
    };

}

#endif /* !FRAMEBUFFER_HPP */
