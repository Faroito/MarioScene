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

    class OBJLoader {
    public:
        explicit OBJLoader(const std::string &path);

        const std::string &getMtlFileName() const;
        const std::vector<std::string> &getMaterialNameList() const;

        unsigned int size();
        const std::string &getGroupsName(unsigned int i) const;
        const Vertices_t &getVertices(unsigned int i) const;
        const Indices_t &getIndices(unsigned int i) const;

    private:
        void loadFile(std::ifstream &file);
        void changeMesh();
        void buildVertices(std::string &str);
        void buildIndices(unsigned int start, unsigned int triangle_nb);
        glm::vec2 getValuesVec2(std::string &str);
        glm::vec3 getValuesVec3(std::string &str);

    private:
        std::string _filePath;
        std::string _mtlFileName;

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
