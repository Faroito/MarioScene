//
// Created by Timothée Couble on 20/10/2019.
//m

#ifndef OBJ_LOADER_HPP
# define OBJ_LOADER_HPP

#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
#include <vector>
#include <algorithm>

#include "glm/glm.hpp"

#include "Misc.hpp"

namespace loader {
    typedef std::vector<Vertex> Vertices_t;
    typedef std::vector<unsigned int> Indices_t;

    class OBJLoader {
    public:
        explicit OBJLoader(const std::string &path);

    private:
        void loadFile(std::ifstream &file);
        void changeMesh();
        void buildVertices(std::string &str);
        void buildIndices(int start, bool quad);
        glm::vec2 getValuesVec2(std::string &str);
        glm::vec3 getValuesVec3(std::string &str);

    private:
        std::string _filePath;
        std::string _mtlPath;

        Vertices_t _vertices;
        Indices_t _indices;
        std::string _groupsName;
        std::string _materialName;
        std::vector<glm::vec3> _position;
        std::vector<glm::vec2> _texture;
        std::vector<glm::vec3> _normal;

        std::vector<Vertices_t> _verticesList;
        std::vector<Indices_t> _indicesList;
        std::vector<std::string> _materialNameList;
        std::vector<std::string> _groupsNameList;
    };
}

#endif /* OBJ_LOADER_HPP */
