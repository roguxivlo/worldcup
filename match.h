#ifndef MATCH_H
#define MATCH_H

#include "square.h"
#include "types.h"

class Match : public Square {
 public:
  static const match_weight_t FRIENDLY = 1;
  static const match_weight_t GROUP_STAGE = 2.5;
  static const match_weight_t FINAL = 4;
  Match(square_name_t const &name, money_t match_fee, match_weight_t weight)
      : Square(name), match_fee(match_fee), weight(weight) {}

 private:
  const money_t match_fee;
  const match_weight_t weight;
};

#endif  // MATCH_H