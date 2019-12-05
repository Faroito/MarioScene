//
// Created by Timothée Couble on 03/11/2019.
//

#include "Mushroom.hpp"

scene::Mushroom::Mushroom(unsigned int id) : Creature(ModelType::MUSHROOM, id) {}

scene::Mushroom::Mushroom(const scene::AObject &other, unsigned int id) : Creature(other, id) {}

scene::Mushroom::~Mushroom() {
    Creature::~Creature();
}

float scene::Mushroom::animate(float time, float beginning, float change, float duration) {
    if (time < duration)
        return ease::inBack(time, beginning, change, duration);
    else if (time > duration && time < duration * 2)
        return change - ease::outBounce(time - duration, beginning, change, duration);
    return 0;
}

void scene::Mushroom::move(const std::vector<std::unique_ptr<AObject>> &objects) {
    auto aTime = (float) glfwGetTime();
    float duration = 1.1f;
    float downtime = 1.0f;
    float maxPos = 0.6f;
    float y = 0;

    y = animate(std::fmod(aTime, duration * 2 + downtime), 0.0f, maxPos, duration);
    _position = glm::vec3(0.0f, y, 0.0f);
}

void scene::Mushroom::orient() {}
