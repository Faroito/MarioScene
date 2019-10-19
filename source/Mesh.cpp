//
// Created by Timothée Couble on 18/10/2019.
//

#include "stb_image.h"

#include "Mesh.hpp"

gl_wrapper::Mesh::Mesh(std::vector<VertexColor> &vertices, std::vector<unsigned int> &indices) {
    _vertices = vertices;
    _indices = indices;
}

gl_wrapper::Mesh::~Mesh() {
    glDeleteVertexArrays(1, &_vaoID);
    glDeleteBuffers(1, &_vboID);
    glDeleteBuffers(1, &_eboID);
}

/*
gl_wrapper::Mesh::Mesh(std::vector<Vertex> &vertices, std::vector<unsigned int> &indices,
        std::vector<Texture> &textures) {
    _vertices = vertices;
    _indices = indices;
    _textures = textures;

    setupMesh();
}*/

void gl_wrapper::Mesh::setupMesh(gl_wrapper::Shader *shader) {
    //setTexture();

    glGenVertexArrays(1, &_vaoID);
    glGenBuffers(1, &_vboID);
    // glGenBuffers(1, &_eboID);

    glBindVertexArray(_vaoID);

    glBindBuffer(GL_ARRAY_BUFFER, _vboID);
    glBufferData(GL_ARRAY_BUFFER, _vertices.size() * sizeof(VertexColor), _vertices.data(), GL_STATIC_DRAW);

    // glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, _eboID);
    // glBufferData(GL_ELEMENT_ARRAY_BUFFER, _indices.size() * sizeof(unsigned int), _indices.data(), GL_STATIC_DRAW);

    GLuint positionID = shader->getAttribLocation("position");
    glEnableVertexAttribArray(positionID);
    glVertexAttribPointer(positionID, 3, GL_FLOAT, GL_FALSE, sizeof(VertexColor), (void *) nullptr);

     GLuint normalID = shader->getAttribLocation("normal");
     glEnableVertexAttribArray(normalID);
     glVertexAttribPointer(normalID, 3, GL_FLOAT, GL_FALSE, sizeof(VertexColor), (void *) (sizeof(glm::vec3)));

    // GLuint textureID = glGetAttribLocation(shader->getId(), "texture");
    // glVertexAttribPointer(textureID, 2, GL_FLOAT, GL_FALSE, sizeof(VertexColor), (void *) (sizeof(glm::vec3) + sizeof(glm::vec4)));
    // glEnableVertexAttribArray(textureID);

    glBindBuffer(GL_ARRAY_BUFFER, 0);
    glBindVertexArray(0);
}

void gl_wrapper::Mesh::setTexture() {
    glGenTextures(1, &_texture);
    glBindTexture(GL_TEXTURE_2D, _texture);
    // set the texture wrapping/filtering options (on the currently bound texture object)
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_REPEAT);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_REPEAT);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);
    // load and generate the texture
    int width, height, nrChannels;
    unsigned char *data = stbi_load("../resource/wooden_container.jpg", &width, &height, &nrChannels, 0);
    if (data)
    {
        glTexImage2D(GL_TEXTURE_2D, 0, GL_RGB, width, height, 0, GL_RGB, GL_UNSIGNED_BYTE, data);
        glGenerateMipmap(GL_TEXTURE_2D);
    }
    else
    {
        std::cout << "Failed to load texture" << std::endl;
    }
    stbi_image_free(data);
}

void gl_wrapper::Mesh::draw() {
    // glBindTexture(GL_TEXTURE_2D, _texture);
    glBindVertexArray(_vaoID);
    glDrawArrays(GL_TRIANGLES, 0, _indices.size());
    // glDrawElements(GL_TRIANGLES, _indices.size(), GL_UNSIGNED_INT, nullptr);
    glBindVertexArray(0);
}
