#ifndef START_H
#define START_H

#include "square.h"
#include "types.h"

class Start : public Square {
public:
    Start(square_name_t const &name, money_t bonus)
            : Square(name), bonus(bonus) {}

    void action(Player &player) override { player.add_money(bonus); }

    void passing_action(Player &player) override { player.add_money(bonus); }

private:
    const money_t bonus;
};

#endif  // START_H