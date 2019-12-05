//
// Created by Timothée Couble on 02/11/2019.
//

#include "BulletBill.hpp"

scene::BulletBill::BulletBill(unsigned int id) : Creature(ModelType::BULLET_BILL, id) {}

scene::BulletBill::BulletBill(const scene::AObject &other, unsigned int id) : Creature(other, id) {}

scene::BulletBill::~BulletBill() {
    Creature::~Creature();
}

void scene::BulletBill::move(const std::vector<std::unique_ptr<AObject>> &objects) {
    auto aTime = glfwGetTime();

    _position = glm::vec3(cos(aTime) * 6.0f, sin(aTime) * 2.0f, sin(aTime) * 4.0f);
}
