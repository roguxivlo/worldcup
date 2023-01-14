#ifndef PENALTY_H
#define PENALTY_H

#include "square.h"
#include "types.h"

class Penalty : public Square {
 public:
  Penalty(square_name_t const& name, money_t penalty_fee)
      : Square(name), penalty_fee(penalty_fee) {}
  void action(Player& player) override { player.add_money(-penalty_fee); }
  void passing_action(Player& player) override { return; }

 private:
  const money_t penalty_fee;
};

#endif  // PENALTY_H