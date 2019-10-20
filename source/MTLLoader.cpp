//
// Created by Timothée Couble on 20/10/2019.
//

#include "MTLLoader.hpp"

loader::MTLLoader::MTLLoader(const std::string &path) : ILoader(path, "mtl file") {}

void loader::MTLLoader::loadFile(std::ifstream &file) {
    std::string line;
    while (std::getline(file, line)) {
        std::string type = line.substr(0, line.find(' '));
        std::string value = line.substr(line.find(' ') + 1, line.size());
        if (type == "newmtl") {
            changeMaterial();
            _materialName = value;
        }
        if (type == "Ka") {
            _material.ambient = getValuesVec3(value);
            if (_material.ambient == glm::vec3(0.0f, 0.0f, 0.0f))
                _material.ambient = glm::vec3(0.04f, 0.04f, 0.04f);
        }
        if (type == "Kd")
            _material.diffuse = getValuesVec3(value);
        if (type == "Ks")
            _material.specular = getValuesVec3(value);
        if (type == "Ns")
            _material.specularExponent = getFloat(value);
        if (type == "Ni")
            _material.opticalDensity = getFloat(value);
        if (type == "illum")
            _material.ilum = std::stoi(value);
    }
    changeMaterial();
}

void loader::MTLLoader::changeMaterial() {
    if (!_materialName.empty())
        _materialList[_materialName] = _material;
    _material = {};
}

loader::Materials_t &loader::MTLLoader::getMaterialList() {
    return _materialList;
}
