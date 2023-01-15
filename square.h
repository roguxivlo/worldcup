#ifndef SQUARE_H
#define SQUARE_H

#include <utility>

#include "types.h"

class Player;

class Square {
public:
    explicit Square(square_name_t name) : name(std::move(name)) {}

    const square_name_t name;

    virtual void action(Player &player) = 0;

    virtual void passing_action([[maybe_unused]] Player &player) = 0;
};

#endif  // SQUARE_H