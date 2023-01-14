#ifndef GOAL_H
#define GOAL_H

#include "square.h"
#include "types.h"

class Goal : public Square {
 public:
  Goal(square_name_t const &name, money_t bonus) : Square(name), bonus(bonus) {}

 private:
  const money_t bonus;
};

#endif  // GOAL_H