#ifndef SQUARE_H
#define SQUARE_H

#include "types.h"

class Player;

class Square {
public:
    Square(square_name_t name) : name(name) {}

    const square_name_t name;

    virtual void action(Player &player) = 0;

    virtual void passing_action(Player &player) = 0;

private:
};

#endif  // SQUARE_H