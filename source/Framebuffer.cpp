//
// Created by Timothée Couble on 04/12/2019.
//

#include "Framebuffer.hpp"

gl_wrapper::Framebuffer::Framebuffer(unsigned int width, unsigned int height) {
    _width = (int) width;
    _height = (int) height;

    for (auto &it : _effectNames) {
        const std::string fsPath = "../shader/framebuffer_" + it + "_fs.glsl";
        auto shader = gl_wrapper::Shader(_vsFramebufferPath, fsPath, gl_wrapper::ShaderType::FRAMEBUFFER_TEXTURE);
        shader.bind();
        shader.setUniformInt("screenTexture", 0);
        gl_wrapper::Shader::unBind();
        _screenShaders.push_back(std::make_unique<gl_wrapper::Shader>(shader));
    }

    auto vertices = loader::getStandardVertices();
    auto indices = loader::getStandardIndices();
    _screenMesh = std::make_unique<Mesh>(gl_wrapper::Mesh(vertices, indices));

    glGenFramebuffers(1, &_fboID);
    this->bind();

    _screenMesh->setFramebufferTexture(width, height);

    glGenRenderbuffers(1, &_rboID);
    glBindRenderbuffer(GL_RENDERBUFFER, _rboID);
    glRenderbufferStorage(GL_RENDERBUFFER, GL_DEPTH24_STENCIL8, width, height);
    glFramebufferRenderbuffer(GL_FRAMEBUFFER, GL_DEPTH_STENCIL_ATTACHMENT, GL_RENDERBUFFER, _rboID);
    if (glCheckFramebufferStatus(GL_FRAMEBUFFER) != GL_FRAMEBUFFER_COMPLETE)
        std::cerr << "Failed to initiate framebuffer." << std::endl;
    gl_wrapper::Framebuffer::unBind();
}

gl_wrapper::Framebuffer::~Framebuffer() {
    glDeleteRenderbuffers(1, &_rboID);
    glDeleteFramebuffers(1, &_fboID);
}

void gl_wrapper::Framebuffer::draw() {
    glPolygonMode(GL_FRONT_AND_BACK, GL_FILL);
    _screenMesh->draw(_screenShaders[shaderIdx]);
}

void gl_wrapper::Framebuffer::passToNextShader() {
    shaderIdx += 1;
    if (shaderIdx >= _screenShaders.size())
        shaderIdx = 0;
}

void gl_wrapper::Framebuffer::setViewPort() {
    glViewport(0, 0, _width, _height);
}

void gl_wrapper::Framebuffer::bind() {
    glBindFramebuffer(GL_FRAMEBUFFER, _fboID);
}

void gl_wrapper::Framebuffer::unBind() {
    glBindFramebuffer(GL_FRAMEBUFFER, 0);
}
