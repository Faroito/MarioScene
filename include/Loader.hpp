//
// Created by Timothée Couble on 20/10/2019.
//

#ifndef LOADER_HPP
# define LOADER_HPP

#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
#include <vector>

#include "glm/glm.hpp"

namespace loader {

    class ILoader {
    public:
        ILoader(const std::string &path, const std::string &type);
        virtual ~ILoader() = default;

        void load();

    protected:
        virtual void loadFile(std::ifstream &file) = 0;
        float getFloat(std::string &str);
        glm::vec2 getValuesVec2(std::string &str);
        glm::vec3 getValuesVec3(std::string &str);

    protected:
        const std::string _fileType;
        const std::string _filePath;
    };
}


#endif /* MARIOSCENE_LOADER_HPP */
