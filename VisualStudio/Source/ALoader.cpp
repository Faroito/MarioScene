//
// Created by Timothée Couble on 20/10/2019.
//

#include "ALoader.hpp"

loader::ALoader::ALoader(const std::string &path, const std::string &type) : _filePath(path), _fileType(type) {}

void loader::ALoader::init() {
    std::ifstream file(_filePath);

    if (file.is_open()) {
        std::cout << "Loading "<< _fileType << " at path: " << _filePath << std::endl;
        loadFile(file);
        file.close();
    } else
        std::cerr << "File failed to load " << _fileType << " at path: " << _filePath << std::endl;
}

float loader::ALoader::getFloat(std::string &str) {
    char *end;

    size_t spaces = std::count(str.begin(), str.end(), ' ');
    if (spaces != 0)
        std::cerr << "Wrong format line: \"" << str << "\" from: " << _filePath << std::endl;

    return std::strtof(str.c_str(), &end);
}

glm::vec2 loader::ALoader::getValuesVec2(std::string &str) {
    char *end;
    glm::vec2 values;

    size_t spaces = std::count(str.begin(), str.end(), ' ');
    if (spaces != 1)
        std::cerr << "Wrong format line: \"" << str << "\" from: " << _filePath << std::endl;

    for (unsigned int i = 0; i < 2; i++) {
        values[i] = std::strtof(str.c_str(), &end);
        str = std::string(end);
    }
    return values;
}

glm::vec3 loader::ALoader::getValuesVec3(std::string &str) {
    char *end;
    glm::vec3 values;

    size_t spaces = std::count(str.begin(), str.end(), ' ');
    if (spaces != 2)
        std::cerr << "Wrong format line: \"" << str << "\" from: " << _filePath << std::endl;

    for (unsigned int i = 0; i < 3; i++) {
        values[i] = std::strtof(str.c_str(), &end);
        str = std::string(end);
    }
    return values;
}
