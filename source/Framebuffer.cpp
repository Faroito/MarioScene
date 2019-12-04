//
// Created by Timothée Couble on 04/12/2019.
//

#include "Framebuffer.hpp"

gl_wrapper::Framebuffer::Framebuffer(unsigned int width, unsigned int height) {
    _width = (int) width;
    _height = (int) height;
    std::string vs_framebuffer_path = "../shader/framebuffers_screen_vs.glsl";
    std::string fs_framebuffer_path = "../shader/framebuffers_screen_fs.glsl";

    _screenShaders.emplace_back(std::make_unique<gl_wrapper::Shader>(
            gl_wrapper::Shader(vs_framebuffer_path, fs_framebuffer_path, gl_wrapper::ShaderType::FRAMEBUFFER_TEXTURE)
    ));
    _screenShaders.front()->bind();
    _screenShaders.front()->setUniformInt("screenTexture", 0);
    gl_wrapper::Shader::unBind();

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
    for (auto &it : _screenShaders)
        _screenMesh->draw(it);
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
