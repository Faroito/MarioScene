//
// Created by Timothée Couble on 20/10/2019.
//

#include "MTLLoader.hpp"

loader::MTLLoader::MTLLoader(const std::string &path) : ALoader(path, "mtl file") {
    _path = path.substr(0, path.find_last_of("/\\") + 1);
}

const loader::MTLLoader &loader::MTLLoader::load() {
    init();
    return *this;
}

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
        if (type == "map_Kd") {
            _textures.push_back({0, _path + value, loader::TextureType::TEXTURE_DIFFUSE});
            _material.type = gl_wrapper::ShaderType::TEXTURE_DIFFUSE;
        } else if (type == "map_Ks") {
            _textures.push_back({0, _path + value, loader::TextureType::TEXTURE_SPECULAR});
            _material.type = gl_wrapper::ShaderType::TEXTURE_SPECULAR;
        }

    }
    changeMaterial();
}

void loader::MTLLoader::changeMaterial() {
    if (!_materialName.empty())
        _materialList[_materialName] = _material;
    if (!_textures.empty())
        _textureMap[_materialName] = _textures;
    _material = {};
    _textures = {};
}

loader::Materials_t &loader::MTLLoader::getMaterialList() {
    return _materialList;
}

bool loader::MTLLoader::hasTextures(const std::string &name) {
    return (_textureMap.find(name) != _textureMap.end());
}

loader::Textures_t &loader::MTLLoader::getTextures(const std::string &name, const std::string &path) {
    return _textureMap[name];
}
