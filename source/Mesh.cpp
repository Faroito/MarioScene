//
// Created by Timothée Couble on 18/10/2019.
//

#include "stb_image.h"

#include "Mesh.hpp"

gl_wrapper::Mesh::Mesh(const loader::Vertices_t &vertices, const loader::Indices_t &indices)
        : _vertices(vertices), _indices(indices) {
    setupMesh();
}

gl_wrapper::Mesh::Mesh(const loader::Vertices_t &vertices, const loader::Indices_t &indices,
        loader::Textures_t &textures) : _vertices(vertices), _indices(indices), _textures(textures) {
    setupMesh();
}

void gl_wrapper::Mesh::setupMesh() {
    for (auto &it : _textures)
        it.id = setTexture(it.path);

    glGenVertexArrays(1, &_vaoID);
    glGenBuffers(1, &_vboID);
    glGenBuffers(1, &_eboID);

    glBindVertexArray(_vaoID);

    glBindBuffer(GL_ARRAY_BUFFER, _vboID);
    glBufferData(GL_ARRAY_BUFFER, _vertices.size() * sizeof(loader::Vertex), _vertices.data(), GL_STATIC_DRAW);

    glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, _eboID);
    glBufferData(GL_ELEMENT_ARRAY_BUFFER, _indices.size() * sizeof(unsigned int), _indices.data(), GL_STATIC_DRAW);

    GLuint positionID = 0;
    glEnableVertexAttribArray(positionID);
    glVertexAttribPointer(positionID, 3, GL_FLOAT, GL_FALSE, sizeof(loader::Vertex),
            (void *) offsetof(loader::Vertex, position));

    GLuint normalID = 1;
    glEnableVertexAttribArray(normalID);
    glVertexAttribPointer(normalID, 3, GL_FLOAT, GL_FALSE, sizeof(loader::Vertex),
            (void *) offsetof(loader::Vertex, normal));

    if (!_textures.empty()) {
        GLuint textureID = 2;
        glVertexAttribPointer(textureID, 2, GL_FLOAT, GL_FALSE, sizeof(loader::Vertex),
                (void *) offsetof(loader::Vertex, textureCord));
        glEnableVertexAttribArray(textureID);
    }

    glBindBuffer(GL_ARRAY_BUFFER, 0);
    glBindVertexArray(0);
}

void gl_wrapper::Mesh::setFramebufferTexture(unsigned int width, unsigned int height) {
    _textures.clear();
    loader::Texture texture = {0, "", loader::TextureType::FRAMEBUFFER_TEXTURE};
    glGenTextures(1, &texture.id);
    glBindTexture(GL_TEXTURE_2D, texture.id);
    glTexImage2D(GL_TEXTURE_2D, 0, GL_RGB, width, height, 0, GL_RGB, GL_UNSIGNED_BYTE, nullptr);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);
    glFramebufferTexture2D(GL_FRAMEBUFFER, GL_COLOR_ATTACHMENT0, GL_TEXTURE_2D, texture.id, 0);
    _textures.emplace_back(texture);
}

void gl_wrapper::Mesh::draw(const Shader_ptr_t &shader) {
    for (int i = 0; i < (int) _textures.size(); i++) {
        glActiveTexture(GL_TEXTURE0 + i);
        std::string name;
        if (_textures[i].type == loader::TextureType::TEXTURE_DIFFUSE)
            name = "diffuse";
        else if (_textures[i].type == loader::TextureType::TEXTURE_SPECULAR)
            name = "specular";
        if (_textures[i].type == loader::TextureType::FRAMEBUFFER_TEXTURE)
            shader->bind();
        else
            shader->setUniformInt(("material." + name).c_str(), i);
        glBindTexture(GL_TEXTURE_2D, _textures[i].id);
    }
    glBindVertexArray(_vaoID);
    glDrawElements(GL_TRIANGLES, (GLsizei) _indices.size(), GL_UNSIGNED_INT, nullptr);
    glBindVertexArray(0);
}

void gl_wrapper::Mesh::clearBuffers() {
     glDeleteVertexArrays(1, &_vaoID);
     glDeleteBuffers(1, &_vboID);
     glDeleteBuffers(1, &_eboID);
}

unsigned int gl_wrapper::Mesh::setTexture(const std::string &path) {
    unsigned int texture = 0;
    int width = 0;
    int height = 0;
    int nbComponents = 0;
    glGenTextures(1, &texture);
    unsigned char *data = stbi_load(path.c_str(), &width, &height, &nbComponents, 0);
    if (data) {
        std::cout << "Loading texture at path: " << path << std::endl;
        GLenum format = GL_RGB;
        if (nbComponents == 1)
            format = GL_RED;
        else if (nbComponents == 3)
            format = GL_RGB;
        else if (nbComponents == 4)
            format = GL_RGBA;

        glBindTexture(GL_TEXTURE_2D, texture);
        glTexImage2D(GL_TEXTURE_2D, 0, format, width, height, 0, format, GL_UNSIGNED_BYTE, data);
        glGenerateMipmap(GL_TEXTURE_2D);

        glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_REPEAT);
        glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_REPEAT);
        glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_NEAREST);
        glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_NEAREST);
    } else
        std::cerr << "Texture failed to load at path: " << path << std::endl;
    stbi_image_free(data);
    return texture;
}
