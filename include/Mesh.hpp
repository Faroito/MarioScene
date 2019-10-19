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
        Mesh(std::vector<Vertex> &vertices, std::vector<unsigned int> &indices);
        Mesh(std::vector<Vertex> &vertices, std::vector<unsigned int> &indices, std::vector<Texture> &textures);
        ~Mesh();

        void setupMesh();

        void draw(Shader *shader);

    private:
        static unsigned int setTexture(const std::string &path);

    private:
        std::vector<Vertex> _vertices;
        std::vector<unsigned int> _indices;
        std::vector<Texture> _textures;

        GLuint _vaoID = 0;
        GLuint _vboID = 0;
        GLuint _eboID = 0;
    };
}

#endif /* !MESH_HPP */
