//
// Created by Timothée Couble on 20/10/2019.
//

#include "OBJLoader.hpp"

loader::OBJLoader::OBJLoader(const std::string &path) : ALoader(path, "obj file") {}

const loader::OBJLoader &loader::OBJLoader::load() {
    init();
    return *this;
}

void loader::OBJLoader::loadFile(std::ifstream &file) {
    std::string line;
    while (std::getline(file, line)) {
        std::string type = line.substr(0, line.find(' '));
        std::string value = line.substr(line.find(' ') + 1, line.size());
        if (type == "g" && value != "default")
            _groupsName = value;
        if (type == "mtllib")
            _mtlFileName = value;
        if (type == "usemtl") {
            changeMesh();
            _materialName = value;
        } if (type == "v")
            _position.push_back(getValuesVec3(value));
        if (type == "vt")
            _texture.push_back(getValuesVec2(value));
        if (type == "vn")
            _normal.push_back(getValuesVec3(value));
        if (type == "f")
            buildVertices(value);
    }
    changeMesh();
}

void loader::OBJLoader::changeMesh() {
    static unsigned int count = 0;
    static std::string lastGroupsName;
    std::string name = _groupsName;

    if (lastGroupsName == _groupsName)
        name = _groupsName + " " + std::to_string(count++);
    else
        count = 0;

    if (!_vertices.empty() && !_indices.empty()) {
        _verticesList.push_back(_vertices);
        _indicesList.push_back(_indices);
        _materialNameList.push_back(_materialName);
        _groupsNameList.push_back(name);
    }

    lastGroupsName = _groupsName;
    _materialName = "";
    _vertices.clear();
    _indices.clear();
}

void loader::OBJLoader::buildVertices(std::string &str) {
    Vertices_t list;
    int index[3] = {};

    unsigned int spaces = (unsigned int) std::count(str.begin(), str.end(), ' ');
	unsigned int del = (unsigned int) std::count(str.begin(), str.end(), '/');
    if (spaces < 2 || del / (spaces + 1) != 2) {
        std::cerr << "Wrong format line: \"" << str << "\" from: " << _filePath << std::endl;
        return;
    }

    for (unsigned int i = 0; i < spaces + 1; i++) {
        size_t posI = str.find(' ');
        std::string token = str.substr(0, posI);
        str.erase(0, posI + 1);
        for (unsigned int j : {0, 1, 2}) {
            size_t posJ = token.find('/');
            index[j] = std::stoi(token.substr(0, posJ)) - 1;
            token.erase(0, posJ + 1);
        }
        loader::Vertex vertex = {};
        vertex.position = _position[index[0]];
        vertex.normal = _normal[index[2]];
        vertex.textureCord = _texture[index[1]];
        list.push_back(vertex);
    }
    buildIndices((unsigned int) _vertices.size(), spaces - 1);
    _vertices.insert(_vertices.end(), list.begin(), list.end());
}

void loader::OBJLoader::buildIndices(unsigned int start, unsigned int triangle_nb) {
    for (unsigned int i = 0; i < triangle_nb; i++) {
        _indices.push_back(start);
        _indices.push_back(start + i + 1);
        _indices.push_back(start + i + 2);
    }
}

const std::string &loader::OBJLoader::getMtlFileName() const {
    return _mtlFileName;
}

unsigned int loader::OBJLoader::size() {
    if (_verticesList.size() != _indicesList.size())
        std::cerr << "Bad initialization from: " << _filePath << std::endl;
    return (unsigned int) _verticesList.size();
}

const std::string &loader::OBJLoader::getGroupsName(unsigned int i) const {
    return _groupsNameList[i];
}

const std::string &loader::OBJLoader::getMaterialName(unsigned int i) const {
    return _materialNameList[i];
}

const loader::Vertices_t &loader::OBJLoader::getVertices(unsigned int i) const {
    return _verticesList[i];
}

const loader::Indices_t &loader::OBJLoader::getIndices(unsigned int i) const {
    return _indicesList[i];
}
