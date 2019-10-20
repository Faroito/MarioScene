//
// Created by Timothée Couble on 18/10/2019.
//

#ifndef MESH_HPP
# define MESH_HPP

#include <iostream>
#include <vector>

#include "glm/glm.hpp"
#include "glm/gtc/matrix_transform.hpp"
#include "glm/gtc/type_ptr.hpp"

#include "Lib.hpp"
#include "Misc.hpp"
#include "Shader.hpp"

namespace gl_wrapper {
    class Mesh {
    public:
        Mesh(const loader::Vertices_t &vertices, const loader::Indices_t &indices);
        Mesh(const loader::Vertices_t &vertices, const loader::Indices_t &indices, std::vector<loader::Texture> &textures);
        ~Mesh();

        void setupMesh();

        void draw(Shader *shader);

    private:
        static unsigned int setTexture(const std::string &path);

    private:
        loader::Vertices_t _vertices;
        loader::Indices_t _indices;
        std::vector<loader::Texture> _textures;

        GLuint _vaoID = 0;
        GLuint _vboID = 0;
        GLuint _eboID = 0;
    };
}

#endif /* !MESH_HPP */
