#ifndef NO_TRAINING_H
#define NO_TRAINING_H

#include "square.h"
#include "types.h"

class NoTraining : public Square {
public:
    NoTraining(square_name_t const &name) : Square(name) {}

    void action(Player &player) override { return; }

    void passing_action(Player &player) override { return; }
};

#endif  // NO_TRAINING_H