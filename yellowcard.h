#ifndef YELLOW_CARD_H
#define YELLOW_CARD_H

#include "square.h"
#include "types.h"

class YellowCard : public Square {
public:
    YellowCard(square_name_t const &name, size_t suspension)
            : Square(name), suspension(suspension) {}

    void action(Player &player) override { player.suspend(suspension); }

    void passing_action(Player &player) override { return; }

private:
    const size_t suspension;
};

#endif  // YELLOW_CARD_H