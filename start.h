#ifndef START_H
#define START_H

#include "square.h"
#include "types.h"

class Start : public Square {
 public:
  Start(square_name_t const &name, money_t bonus)
      : Square(name), bonus(bonus) {}

 private:
  const money_t bonus;
};

#endif  // START_H