//
// Created by Timothée Couble on 20/10/2019.
//

#ifndef ALOADER_HPP
# define ALOADER_HPP

#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
#include <vector>
#include <algorithm>

#include "glm/glm.hpp"

namespace loader {

    class ALoader {
    public:
        ALoader(const std::string &path, const std::string &type);
        virtual ~ALoader() = default;

    protected:
        void init();
        virtual void loadFile(std::ifstream &file) = 0;
        float getFloat(std::string &str);
        glm::vec2 getValuesVec2(std::string &str);
        glm::vec3 getValuesVec3(std::string &str);

    protected:
        const std::string _filePath;

    private:
        const std::string _fileType;
    };

}

#endif /* !ALOADER_HPP */
