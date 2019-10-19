//
// Created by Timothée Couble on 18/10/2019.
//

#include "stb_image.h"

#include "Mesh.hpp"

gl_wrapper::Mesh::Mesh(std::vector<Vertex> &vertices, std::vector<unsigned int> &indices)
    : _vertices(vertices), _indices(indices) {
    setupMesh();
}

gl_wrapper::Mesh::Mesh(std::vector<Vertex> &vertices, std::vector<unsigned int> &indices,
        std::vector<Texture> &textures) : _vertices(vertices), _indices(indices), _textures(textures) {
    setupMesh();
}

gl_wrapper::Mesh::~Mesh() {
    glDeleteVertexArrays(1, &_vaoID);
    glDeleteBuffers(1, &_vboID);
    glDeleteBuffers(1, &_eboID);
}

void gl_wrapper::Mesh::setupMesh() {
    for (auto &it : _textures)
        it.id = setTexture(it.path);

    glGenVertexArrays(1, &_vaoID);
    glGenBuffers(1, &_vboID);
    glGenBuffers(1, &_eboID);

    glBindVertexArray(_vaoID);

    glBindBuffer(GL_ARRAY_BUFFER, _vboID);
    glBufferData(GL_ARRAY_BUFFER, _vertices.size() * sizeof(Vertex), _vertices.data(), GL_STATIC_DRAW);

    glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, _eboID);
    glBufferData(GL_ELEMENT_ARRAY_BUFFER, _indices.size() * sizeof(unsigned int), _indices.data(), GL_STATIC_DRAW);

    GLuint positionID = 0;
    glEnableVertexAttribArray(positionID);
    glVertexAttribPointer(positionID, 3, GL_FLOAT, GL_FALSE, sizeof(Vertex), (void *) offsetof(Vertex, position));

    GLuint normalID = 1;
    glEnableVertexAttribArray(normalID);
    glVertexAttribPointer(normalID, 3, GL_FLOAT, GL_FALSE, sizeof(Vertex), (void *) offsetof(Vertex, normal));

    if (!_textures.empty()) {
        GLuint textureID = 2;
        glVertexAttribPointer(textureID, 2, GL_FLOAT, GL_FALSE, sizeof(Vertex), (void *) offsetof(Vertex, textureCord));
        glEnableVertexAttribArray(textureID);
    }

    glBindBuffer(GL_ARRAY_BUFFER, 0);
    glBindVertexArray(0);
}

void gl_wrapper::Mesh::draw(Shader *shader) {
    for (int i = 0; i < (int) _textures.size(); i++) {
        glActiveTexture(GL_TEXTURE0 + i);
        std::string name;
        if (_textures[i].type == TEXTURE_DIFFUSE)
            name = "diffuse";
        else if (_textures[i].type == TEXTURE_SPECULAR)
            name = "specular";
        shader->setUniformInt(("material." + name).c_str(), i);
        glBindTexture(GL_TEXTURE_2D, _textures[i].id);
    }
    glBindVertexArray(_vaoID);
    // glDrawArrays(GL_TRIANGLES, 0, 36);
    glDrawElements(GL_TRIANGLES, _indices.size(), GL_UNSIGNED_INT, nullptr);
    glBindVertexArray(0);
}

unsigned int gl_wrapper::Mesh::setTexture(const std::string &path) {
    unsigned int texture = 0;
    int width = 0;
    int height = 0;
    int nbComponents = 0;
    glGenTextures(1, &texture);
    unsigned char *data = stbi_load(path.c_str(), &width, &height, &nbComponents, 0);
    if (data) {
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
        glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR_MIPMAP_LINEAR);
        glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);
    } else
        std::cout << "Texture failed to load at path: " << path << std::endl;
    stbi_image_free(data);
    return texture;
}
