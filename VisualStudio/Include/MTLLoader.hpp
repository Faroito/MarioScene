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
        bool hasTextures(const std::string &name);
        Textures_t &getTextures(const std::string &name, const std::string &path = "");

    private:
        void loadFile(std::ifstream &file) override;
        void changeMaterial();

    private:
        std::string _path;
        std::string _materialName;
        Material _material = {};
        Textures_t _textures = {};
        Materials_t _materialList;
        TexturesMap_t _textureMap;
    };

}

#endif /* !MTL_LOADER_HPP */
