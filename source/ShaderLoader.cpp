//
// Created by Timothée Couble on 20/10/2019.
//

#include "ShaderLoader.hpp"

loader::ShaderLoader::ShaderLoader(const std::string &path) : ALoader(path, "shader") {}

const loader::ShaderLoader &loader::ShaderLoader::load() {
    init();
    return *this;
}

void loader::ShaderLoader::loadFile(std::ifstream &file) {
    std::string line;
    std::getline(file, line);
    _shader += getShaderVersion();
    while (std::getline(file, line)) {
        _shader += line;
        _shader += '\n';
    }
}

const char *loader::ShaderLoader::getShader() const {
    return _shader.c_str();
}

#if _MSC_VER
    std::string loader::ShaderLoader::getShaderVersion() {
        return "#version 430 core";
    }
#else
    std::string loader::ShaderLoader::getShaderVersion() {
        return "#version 410 core";
    }
#endif
