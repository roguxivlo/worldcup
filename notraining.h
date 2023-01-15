#ifndef NO_TRAINING_H
#define NO_TRAINING_H

#include "square.h"
#include "types.h"

class NoTraining : public Square {
public:
    explicit NoTraining(square_name_t const &name) : Square(name) {}

    void action([[maybe_unused]] Player &player) override {  }

    void passing_action([[maybe_unused]] Player &player) override {  }
};

#endif  // NO_TRAINING_H