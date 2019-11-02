//
// Created by Timothée Couble on 02/11/2019.
//

#ifndef CONFIG_LOADER_HPP
# define CONFIG_LOADER_HPP

#include <iostream>
#include <string>
#include <vector>
#include <unordered_map>
#include <algorithm>
#include <memory>

#include "ALoader.hpp"
#include "AObject.hpp"
#include "BulletBill.hpp"
#include "Creature.hpp"
#include "Misc.hpp"

namespace loader {

    class ConfigLoader : public ALoader {
    public:
        explicit ConfigLoader(const std::string &path);

        const loader::ConfigLoader &load();
        scene::Objects_t &getObjects();
        std::unordered_map<scene::ModelType, std::string> getPath() const;

    private:
        void loadFile(std::ifstream &file) override;
        void createObject(std::string &str);
        void copyObject();
        void readSize(std::string &str);
        void readDir(std::string &str);
        void readOffset(std::string &str);
        void readPos(std::string &str);

    private:
        bool _new = false;
        scene::Objects_t _objects;
        const std::unordered_map<std::string, scene::ModelType> _modelMap = {
                {"block", scene::ModelType::BLOCK},
                {"grass_block", scene::ModelType::GRASS_BLOCK},
                {"question_block", scene::ModelType::QUESTION_BLOCK},
                {"pipe", scene::ModelType::PIPE},
                {"mushroom", scene::ModelType::MUSHROOM},
                {"goompa", scene::ModelType::GOOMPA},
                {"piranha_plant", scene::ModelType::PIRANHA_PLANT},
                {"bullet_bill", scene::ModelType::BULLET_BILL},
        };
    };

}

#endif /* !CONFIG_LOADER_HPP */
