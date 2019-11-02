//
// Created by Timothée Couble on 02/11/2019.
//

#include "BulletBill.hpp"

scene::BulletBill::BulletBill() : Creature(ModelType::BULLET_BILL) {}

scene::BulletBill::BulletBill(const scene::AObject &other) : Creature(other) {}

void scene::BulletBill::move() {
    auto aTime = (float) glfwGetTime();

    _position = glm::vec3(cos(aTime) * 6.0f, sin(aTime) * 2.0f, sin(aTime) * 4.0f);
}
