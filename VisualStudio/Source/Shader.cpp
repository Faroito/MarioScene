//
// Created by Timothée Couble on 17/10/2019.
//

#include "Shader.hpp"

gl_wrapper::Shader::Shader(const std::string &vs_path, const std::string &fs_path,
        ShaderType type) : _type(type) {
    _sID = glCreateProgram();
    GLuint vID = glCreateShader(GL_VERTEX_SHADER);
    GLuint fID = glCreateShader(GL_FRAGMENT_SHADER);

    auto vert = loader::ShaderLoader(vs_path).load();
    auto frag = loader::ShaderLoader(fs_path).load();

    compileShader(vID, vert.getShader());
    compileShader(fID, frag.getShader());

    glLinkProgram(_sID);

    linkCheck(_sID);

    glDeleteShader(vID);
    glDeleteShader(fID);
}

void gl_wrapper::Shader::compileShader(GLuint ID, const char *shader) {
    glShaderSource(ID, 1, &shader, nullptr);
    glCompileShader(ID);
    compilerCheck(ID);
    glAttachShader(_sID, ID);
}

void gl_wrapper::Shader::compilerCheck(GLuint ID) {
    GLint comp;

    glGetShaderiv(ID, GL_COMPILE_STATUS, &comp);
    if (comp == GL_FALSE) {
        std::cerr << "Shader Compilation FAILED" << std::endl;
        GLchar messages[256];
        glGetShaderInfoLog(ID, sizeof(messages),0,&messages[0]);
        std::cerr << messages;
    }
}

void gl_wrapper::Shader::linkCheck(GLuint ID) {
    GLint linkStatus, validateStatus;

    glGetProgramiv(ID, GL_LINK_STATUS, &linkStatus);
    if(linkStatus == GL_FALSE ){
        std::cerr << "Shader Linking FAILED" << std::endl;
        GLchar messages[256];
        glGetProgramInfoLog(ID, sizeof(messages),0,&messages[0]);
        std::cerr << messages;
    }

    glValidateProgram(ID);
    glGetProgramiv(ID, GL_VALIDATE_STATUS, &validateStatus);
    std::cout << "Link: " << linkStatus << "  Validate: " << validateStatus << std::endl;
    if(linkStatus == GL_FALSE ){
        std::cerr << "Shader Validation FAILED" << std::endl;
        GLchar messages[256];
        glGetProgramInfoLog(ID, sizeof(messages),0,&messages[0]);
        std::cerr << messages;
    }

}

void gl_wrapper::Shader::bind() {
    glUseProgram(_sID);
}

void gl_wrapper::Shader::unBind() {
    glUseProgram(0);
}

void gl_wrapper::Shader::setUniformInt(const char *name, int i) const {
    GLint intID = glGetUniformLocation(_sID, name);
    glUniform1iv(intID, 1, &i);
}

void gl_wrapper::Shader::setUniformFloat(const char *name, const float f) const {
    GLint floatID = glGetUniformLocation(_sID, name);
    glUniform1fv(floatID, 1, &f);
}

void gl_wrapper::Shader::setUniformVector3(const char *name, const glm::vec3 &vector) const {
    GLint vectorID = glGetUniformLocation(_sID, name);
    glUniform3fv(vectorID, 1, glm::value_ptr(vector));
}

void gl_wrapper::Shader::setUniformMatrix4(const char *name, const glm::mat4 &matrix) const {
    GLint matrixID = glGetUniformLocation(_sID, name);
    glUniformMatrix4fv(matrixID, 1, GL_FALSE, glm::value_ptr(matrix));
}

gl_wrapper::ShaderType gl_wrapper::Shader::getType() const {
    return _type;
}
