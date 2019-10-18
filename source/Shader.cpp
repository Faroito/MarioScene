//
// Created by Timothée Couble on 17/10/2019.
//

#include "Shader.hpp"

gl_wrapper::Shader::Shader(const char *vert, const char *frag) {
    _sID = glCreateProgram();
    GLuint vID = glCreateShader(GL_VERTEX_SHADER);
    GLuint fID = glCreateShader(GL_FRAGMENT_SHADER);

    glShaderSource(vID, 1, &vert, nullptr);
    glShaderSource(fID, 1, &frag, nullptr);

    glCompileShader(vID);
    glCompileShader(fID);

    compilerCheck(vID);
    compilerCheck(fID);

    glAttachShader(_sID, vID);
    glAttachShader(_sID, fID);

    glLinkProgram(_sID);

    linkCheck(_sID);

    bind();
}

void gl_wrapper::Shader::bind() {
    glUseProgram(_sID);
}

void gl_wrapper::Shader::unBind() {
    glUseProgram(0);
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

GLuint gl_wrapper::Shader::getId() const {
    return _sID;
}

