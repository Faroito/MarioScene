//
// Created by Timothée Couble on 20/10/2019.
//

#include "OBJLoader.hpp"

loader::OBJLoader::OBJLoader(const std::string &path) {
    std::ifstream file(path);
    _filePath = path;

    if (file.is_open()) {
        loadFile(file);
        file.close();
    } else
        std::cerr << "Obj file failed to load at path: " << path << std::endl;
}

void loader::OBJLoader::loadFile(std::ifstream &file) {
    std::string line;
    while (std::getline(file, line)) {
        std::string type = line.substr(0, line.find(' '));
        std::string value = line.substr(line.find(' ') + 1, line.size());
        if (type == "g" && value != "default")
            _groupsName = value;
        if (type == "mtllib")
            _mtlPath = value;
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
    for (size_t i = 0; i < _verticesList.size(); i++) {
        std::cout << _groupsNameList[i] << std::endl;
        std::cout << _materialNameList[i] << std::endl;
        std::cout << _verticesList[i].size()<< std::endl;
        std::cout << _indicesList[i].size() << std::endl;
        std::cout << std::endl;
    }
}

void loader::OBJLoader::changeMesh() {
    if (!_vertices.empty() && !_indices.empty()) {
        _verticesList.push_back(_vertices);
        _indicesList.push_back(_indices);
        _materialNameList.push_back(_materialName);
        _groupsNameList.push_back(_groupsName);
    }

    _materialName = "";
    _vertices.clear();
    _indices.clear();
}

void loader::OBJLoader::buildVertices(std::string &str) {
    Vertices_t list;
    int index[3] = {};

    size_t spaces = std::count(str.begin(), str.end(), ' ');
    size_t del = std::count(str.begin(), str.end(), '/');
    if (!(spaces == 2 || spaces == 3) || del / (spaces + 1) != 2) {
        std::cerr << "Wrong format line: \"" << str << "\" from:" << _filePath << std::endl;
        return;
    }

    for (size_t i = 0; i < spaces + 1; i++) {
        int posI = str.find(' ');
        std::string token = str.substr(0, posI);
        str.erase(0, posI + 1);
        for (int j : {0, 1, 2}) {
            int posJ = token.find('/');
            index[j] = std::stoi(token.substr(0, posJ));
            token.erase(0, posJ + 1);
        }
        loader::Vertex vertex = {};
        vertex.position = _position[index[0]];
        vertex.normal = _normal[index[2]];
        vertex.textureCord = _texture[index[1]];
        list.push_back(vertex);
    }
    buildIndices(_vertices.size(), spaces == 3);
    _vertices.insert(_vertices.end(), list.begin(), list.end());
}

void loader::OBJLoader::buildIndices(int start, bool quad) {
    _indices.push_back(start);
    _indices.push_back(start + 1);
    _indices.push_back(start + 2);
    if (quad) {
        _indices.push_back(start);
        _indices.push_back(start + 2);
        _indices.push_back(start + 3);
    }
}

glm::vec2 loader::OBJLoader::getValuesVec2(std::string &str) {
    char *end;
    glm::vec2 values;

    size_t spaces = std::count(str.begin(), str.end(), ' ');
    if (spaces != 1)
        std::cerr << "Wrong format line: \"" << str << "\" from:" << _filePath << std::endl;

    for (unsigned int i = 0; i < 2; i++) {
        values[i] = std::strtod(str.c_str(), &end);
        str = std::string(end);
    }
    return values;
}

glm::vec3 loader::OBJLoader::getValuesVec3(std::string &str) {
    char *end;
    glm::vec3 values;

    size_t spaces = std::count(str.begin(), str.end(), ' ');
    if (spaces != 2)
        std::cerr << "Wrong format line: \"" << str << "\" from:" << _filePath << std::endl;

    for (unsigned int i = 0; i < 3; i++) {
        values[i] = std::strtod(str.c_str(), &end);
        str = std::string(end);
    }
    return values;
}
