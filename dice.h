#ifndef DICE_H
#define DICE_H

#include "worldcup.h"
#include <vector>

class Dice {
public:

    void add_die(std::shared_ptr<Die> die) {
        dice.push_back(die);
    }

    unsigned short roll() {
        unsigned short sum = 0;
        for (auto &die: dice) {
            sum += die->roll();
        }
        return sum;
    }

private:
    std::vector<std::shared_ptr<Die>> dice;
};

#endif  // DICE_H