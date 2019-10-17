//
// Created by Timothée Couble on 17/10/2019.
//

#include "Shader.hpp"

glew_wrapper::Shader::Shader(const char *vert, const char *frag) {
    _sID = glCreateProgram();
    GLuint vID = glCreateShader(GL_VERTEX_SHADER);
    GLuint fID = glCreateShader(GL_FRAGMENT_SHADER);

    glShaderSource(vID, 1, &vert, nullptr);
    glShaderSource(fID, 1, &frag, nullptr);

    glCompileShader(vID);
    glCompileShader(fID);

    compilerCheck(vID);
    compilerCheck(fID);

    glAttachShader(_sID,vID);
    glAttachShader(_sID,fID);

    glLinkProgram(_sID);

    linkCheck(_sID);

    bind();
}

void glew_wrapper::Shader::bind() {
    glUseProgram(_sID);
}

void glew_wrapper::Shader::unBind() {
    glUseProgram(0);
}

void glew_wrapper::Shader::compilerCheck(GLuint ID) {
    GLint comp;

    glGetShaderiv(ID, GL_COMPILE_STATUS, &comp);
    if (comp == GL_FALSE) {
        std::cout << "Shader Compilation FAILED" << std::endl;
        GLchar messages[256];
        glGetShaderInfoLog(ID, sizeof(messages),0,&messages[0]);
        std::cout << messages;
    }
}

void glew_wrapper::Shader::linkCheck(GLuint ID) {
    GLint linkStatus, validateStatus;

    glGetProgramiv(ID, GL_LINK_STATUS, &linkStatus);
    if(linkStatus == GL_FALSE ){
        std::cout << "Shader Linking FAILED" << std::endl;
        GLchar messages[256];
        glGetProgramInfoLog(ID, sizeof(messages),0,&messages[0]);
        std::cout << messages;
    }

    glValidateProgram(ID);
    glGetProgramiv(ID, GL_VALIDATE_STATUS, &validateStatus);
    std::cout << "Link: " << linkStatus << "  Validate: " << validateStatus << std::endl;
    if(linkStatus == GL_FALSE ){
        std::cout << "Shader Validation FAILED" << std::endl;
        GLchar messages[256];
        glGetProgramInfoLog(ID, sizeof(messages),0,&messages[0]);
        std::cout << messages;
    }

}

GLuint glew_wrapper::Shader::getId() const {
    return _sID;
}

