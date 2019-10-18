//
// Created by Timothée Couble on 18/10/2019.
//

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
    glGenVertexArrays(1, &_vaoID);
    glGenBuffers(1, &_vboID);
    glGenBuffers(1, &_eboID);

    glBindVertexArray(_vaoID);

    glBindBuffer(GL_ARRAY_BUFFER, _vboID);
    glBufferData(GL_ARRAY_BUFFER, _vertices.size() * sizeof(VertexColor), _vertices.data(), GL_STATIC_DRAW);

    glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, _eboID);
    glBufferData(GL_ELEMENT_ARRAY_BUFFER, _indices.size() * sizeof(unsigned int), _indices.data(), GL_STATIC_DRAW);

    GLuint positionID = glGetAttribLocation(shader->getId(), "position");
    glEnableVertexAttribArray(positionID);
    glVertexAttribPointer(positionID, 3, GL_FLOAT, GL_FALSE, sizeof(VertexColor), (void *) nullptr);

    GLuint colorID = glGetAttribLocation(shader->getId(), "color");
    glEnableVertexAttribArray(colorID);
    glVertexAttribPointer(colorID, 4, GL_FLOAT, GL_FALSE, sizeof(VertexColor), (void *) (1 * sizeof(glm::vec3)));

    glBindBuffer(GL_ARRAY_BUFFER, 0);
    glBindVertexArray(0);
}

void gl_wrapper::Mesh::draw() {
    glBindVertexArray(_vaoID);
    glDrawElements(GL_TRIANGLES, _indices.size(), GL_UNSIGNED_INT, nullptr);
    glBindVertexArray(0);
}
