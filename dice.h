#ifndef DICE_H
#define DICE_H

#include "worldcup.h"
#include <vector>

class Dice {
public:

    void add_die(const std::shared_ptr<Die>& die) {
        dice.push_back(die);
    }

    size_t roll() const {
        size_t sum = 0;
        for (auto &die: dice) {
            sum += die->roll();
        }
        return sum;
    }

private:
    std::vector<std::shared_ptr<Die>> dice;
};

#endif  // DICE_H