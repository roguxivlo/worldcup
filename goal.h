#ifndef GOAL_H
#define GOAL_H

#include "square.h"
#include "types.h"

class Goal : public Square {
public:
    Goal(square_name_t const &name, money_t bonus) : Square(name), bonus(bonus) {}

    void action(Player &player) override {
        player.add_money(bonus);
    }

    void passing_action([[maybe_unused]] Player &player) override {  }

private:
    const money_t bonus;
};

#endif  // GOAL_H