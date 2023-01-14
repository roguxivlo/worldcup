#ifndef BOOKIE_H
#define BOOKIE_H

#include "square.h"
#include "types.h"

class Bookie : public Square {
 public:
  Bookie(square_name_t const &name, size_t win_rate, money_t prize,
         money_t loss)
      : Square(name), win_rate(win_rate), prize(prize), loss(loss) {}

 private:
  const size_t win_rate;
  const money_t prize;
  const money_t loss;
};

#endif  // BOOKIE_H