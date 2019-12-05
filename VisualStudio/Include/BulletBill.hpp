//
// Created by Timothée Couble on 02/11/2019.
//

#ifndef BULLET_BILL_HPP
# define BULLET_BILL_HPP

#include "Creature.hpp"

namespace scene {

    class BulletBill : public Creature {
    public:
        explicit BulletBill(unsigned int id);
        BulletBill(const AObject& other, unsigned int id);
        ~BulletBill() final;

    private:
        void move(const std::vector<std::unique_ptr<AObject>> &objects) override;
    };

}

#endif /* !BULLET_BILL_HPP */
