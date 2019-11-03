//
// Created by Timothée Couble on 03/11/2019.
//

#ifndef MUSHROOM_HPP
# define MUSHROOM_HPP

# define _USE_MATH_DEFINES
#include <cmath>

#include "Creature.hpp"
#include "EasingFunctions.hpp"

namespace scene {

    class Mushroom : public Creature {
    public:
        explicit Mushroom(unsigned int id);
        Mushroom(const AObject& other, unsigned int id);
        ~Mushroom() final;

    private:
        void move(const std::vector<std::unique_ptr<AObject>> &objects) override;
        void orient() override;

        static float animate(float time, float beginning, float change, float duration);

    private:
        bool _goUp = true;
    };

}

#endif /* !MUSHROOM_HPP */
