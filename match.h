#ifndef MATCH_H
#define MATCH_H

#include "square.h"
#include "types.h"

class Match : public Square {
 public:
  Match(square_name_t const &name, money_t match_fee)
      : Square(name), match_fee(match_fee) {}

 private:
  const money_t match_fee;
};

#endif  // MATCH_H