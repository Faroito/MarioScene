//
// Created by Timothée Couble on 20/10/2019.
//

#ifndef MTL_LOADER_HPP
# define MTL_LOADER_HPP

#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
#include <unordered_map>
#include <algorithm>

#include "glm/glm.hpp"

#include "ALoader.hpp"
#include "Misc.hpp"

namespace loader {

    class MTLLoader : public ALoader {
    public:
        explicit MTLLoader(const std::string &path);

        const loader::MTLLoader &load();
        Materials_t &getMaterialList();

    private:
        void loadFile(std::ifstream &file) override;
        void changeMaterial();

    private:
        std::string _materialName;
        Material _material = {};
        Materials_t _materialList;
    };

}

#endif /* !MTL_LOADER_HPP */
