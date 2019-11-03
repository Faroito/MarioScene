//
// Created by Timothée Couble on 02/11/2019.
//

#include "ConfigLoader.hpp"

loader::ConfigLoader::ConfigLoader(const std::string &path) : ALoader(path, "config file") {}

loader::ConfigLoader::~ConfigLoader() {
    _objects.clear();
}

const loader::ConfigLoader &loader::ConfigLoader::load() {
    init();
    return *this;
}

void loader::ConfigLoader::loadFile(std::ifstream &file) {
    std::string line;
    while (std::getline(file, line)) {
        std::string type = line.substr(0, line.find(' '));
        std::string value = line.substr(line.find(' ') + 1, line.size());
        if (type == "new")
            createObject(value);
        if (type == "size")
            readSize(value);
        if (type == "dir")
            readDir(value);
        if (type == "shape")
            readShape(value);
        if (type == "offset")
            readOffset(value);
        if (type == "pos")
            readPos(value);
    }
}

void loader::ConfigLoader::createObject(std::string &str) {
    auto i = _objects.size();
    scene::Objects_ptr_t object;
    if (_modelMap.find(str) == _modelMap.end())
        object = std::make_unique<scene::AObject>(scene::AObject(scene::ModelType::UNKNOWN, i));
    else {
        scene::ModelType type = _modelMap.at(str);
        switch (type) {
            case scene::ModelType::BULLET_BILL:
                object = std::make_unique<scene::BulletBill>(scene::BulletBill(i));
                break;
            case scene::ModelType::MUSHROOM:
                object = std::make_unique<scene::Mushroom>(scene::Mushroom(i));
                break;
            case scene::ModelType::GOOMPA:
                object = std::make_unique<scene::Creature>(scene::Creature(type, i));
                break;
            default:
                object = std::make_unique<scene::AObject>(scene::AObject(type, i));
        }
    }
    _objects.push_back(std::move(object));
    _new = true;

}

void loader::ConfigLoader::copyObject() {
    auto i = _objects.size();
    scene::ModelType type = _objects.back()->getType();
    scene::Objects_ptr_t object;
    switch (type) {
        case scene::ModelType::BULLET_BILL:
            object = std::make_unique<scene::BulletBill>(scene::BulletBill(*_objects.back(), i));
            break;
        case scene::ModelType::MUSHROOM:
            object = std::make_unique<scene::Mushroom>(scene::Mushroom(*_objects.back(), i));
            break;
        case scene::ModelType::GOOMPA:
            object = std::make_unique<scene::Creature>(scene::Creature(*_objects.back(), i));
            break;
        default:
            object = std::make_unique<scene::AObject>(scene::AObject(*_objects.back(), i));
    }
    _objects.push_back(std::move(object));
}

void loader::ConfigLoader::readSize(std::string &str) {
    if (!_new)
        return;
    unsigned int spaces = (unsigned int) std::count(str.begin(), str.end(), ' ');
    if (spaces == 0)
        _objects.back()->setSize(glm::vec3(getFloat(str)));
    else if (spaces == 2)
        _objects.back()->setSize(getValuesVec3(str));
    else
        std::cerr << "Wrong format line: \"" << str << "\" from: " << _filePath << std::endl;
}

void loader::ConfigLoader::readDir(std::string &str) {
    if (!_new)
        return;
    unsigned int spaces = (unsigned int) std::count(str.begin(), str.end(), ' ');
    if (spaces == 0)
        _objects.back()->setOrientation(glm::vec3(0.0f, getFloat(str), 0.0f));
    else if (spaces == 2)
        _objects.back()->setOrientation(getValuesVec3(str));
    else
        std::cerr << "Wrong format line: \"" << str << "\" from: " << _filePath << std::endl;
}

void loader::ConfigLoader::readShape(std::string &str) {
    if (!_new)
        return;
    unsigned int spaces = (unsigned int) std::count(str.begin(), str.end(), ' ');
    if (spaces == 2)
        _objects.back()->setShape(getValuesVec3(str));
    else
        std::cerr << "Wrong format line: \"" << str << "\" from: " << _filePath << std::endl;
}

void loader::ConfigLoader::readOffset(std::string &str) {
    if (!_new)
        return;
    unsigned int spaces = (unsigned int) std::count(str.begin(), str.end(), ' ');
    if (spaces == 2)
        _objects.back()->setOffset(getValuesVec3(str));
    else
        std::cerr << "Wrong format line: \"" << str << "\" from: " << _filePath << std::endl;
}

void loader::ConfigLoader::readPos(std::string &str) {
    if (!_new)
        copyObject();
    unsigned int spaces = (unsigned int) std::count(str.begin(), str.end(), ' ');
    if (spaces == 1) {
        auto pos = getValuesVec2(str);
        _objects.back()->setPosition(glm::vec3(pos.x, pos.y, 0.0f));
    } else if (spaces == 2)
        _objects.back()->setPosition(getValuesVec3(str));
    else
        std::cerr << "Wrong format line: \"" << str << "\" from: " << _filePath << std::endl;
    _new = false;
}

scene::Objects_t &loader::ConfigLoader::getObjects() {
    return _objects;
}

std::unordered_map<scene::ModelType, std::string> loader::ConfigLoader::getPath() const {
    std::unordered_map<scene::ModelType, std::string> paths;
    for (const auto &it : _modelMap) {
        auto findBlock = [&it](scene::Objects_ptr_t const& obj) { return obj->getType() == it.second; };
        auto foundItem = std::find_if(_objects.begin(), _objects.end(), findBlock);
        if (foundItem != std::end(_objects))
            paths.insert({it.second, "../resource/" + it.first + ".obj"});
    }
    return paths;
}
