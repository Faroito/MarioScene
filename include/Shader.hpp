//
// Created by Timothée Couble on 17/10/2019.
//

#ifndef SHADER_HPP
# define SHADER_HPP

#include <iostream>

#include "Lib.hpp"

namespace gl_wrapper {
    class Shader {
    public:
        Shader(const char *vert, const char *frag);

        void bind();
        void unBind();

        GLuint getId() const;

    private:
        void compilerCheck(GLuint ID);
        void linkCheck(GLuint ID);

    private:
        GLuint _sID;
    };
}

#endif /* !SHADER_HPP */
