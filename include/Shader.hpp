//
// Created by Timothée Couble on 17/10/2019.
//

#ifndef SHADER_HPP
# define SHADER_HPP

#include <iostream>
#include <fstream>
#include <string>
#include <sstream>

#include "glm/glm.hpp"
#include "glm/gtc/type_ptr.hpp"

#include "Lib.hpp"
#include "Misc.hpp"

namespace gl_wrapper {
    class Shader {
    public:
        Shader(const std::string &vs_path, const std::string &fs_path);

        void bind();
        static void unBind();

        void setUniformFloat(const char *name, float f);
        void setUniformVector3(const char *name, const glm::vec3 &vector);
        void setUniformMatrix4(const char *name, const glm::mat4 &matrix);
        GLuint getAttribLocation(const char *name);

    private:
        static std::string readShader(const std::string &name);
        void compileShader(GLuint ID, const char *shader);
        static void compilerCheck(GLuint ID);
        static void linkCheck(GLuint ID);

    private:
        GLuint _sID;
    };
}

#endif /* !SHADER_HPP */
