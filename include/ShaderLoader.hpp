//
// Created by Timothée Couble on 20/10/2019.
//

#ifndef SHADER_LOADER_HPP
# define SHADER_LOADER_HPP

#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
#include <vector>
#include <algorithm>

#include "glm/glm.hpp"

#include "ALoader.hpp"

namespace loader {

    class ShaderLoader : public ALoader {
    public:
        explicit ShaderLoader(const std::string &path);

        const loader::ShaderLoader &load();
        const char *getShader() const;

    private:
        void loadFile(std::ifstream &file) override;
        static std::string getShaderVersion();

    private:
        std::string _shader;
    };

}

#endif /* !SHADER_LOADER_HPP */
