//
// Created by Timothée Couble on 17/10/2019.
//

#ifndef SHADER_HPP
# define SHADER_HPP

#include <iostream>
#include <vector>
#include <memory>

#include "glm/glm.hpp"
#include "glm/gtc/type_ptr.hpp"

#include "Lib.hpp"
#include "Misc.hpp"
#include "ShaderLoader.hpp"

namespace gl_wrapper {

    class Shader {
    public:
        Shader(const std::string &vs_path, const std::string &fs_path, ShaderType type);
		~Shader() = default;

        void bind();
        static void unBind();

        void setUniformInt(const char *name, int i) const;
        void setUniformFloat(const char *name, float f) const;
        void setUniformVector3(const char *name, const glm::vec3 &vector) const;
        void setUniformMatrix4(const char *name, const glm::mat4 &matrix) const;
        ShaderType getType() const;

    private:
        void compileShader(GLuint ID, const char *shader);
        static void compilerCheck(GLuint ID);
        static void linkCheck(GLuint ID);

    private:
        const ShaderType _type;
        GLuint _sID;
    };

    typedef std::unique_ptr<Shader> Shader_ptr_t;
    typedef std::vector<Shader_ptr_t> Shaders_t;
}

#endif /* !SHADER_HPP */
