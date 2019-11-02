//
// Created by Timothée Couble on 02/11/2019.
//

#ifndef BULLET_BILL_HPP
# define BULLET_BILL_HPP

#include "Creature.hpp"

namespace scene {

    class BulletBill : public Creature {
    public:
        BulletBill();
        explicit BulletBill(const AObject& other);

    private:
        void move() override;
    };

}

#endif /* !BULLET_BILL_HPP */
