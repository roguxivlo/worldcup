#ifndef BOOKIE_H
#define BOOKIE_H

#include "square.h"
#include "types.h"

class Bookie : public Square {
 public:
  Bookie(square_name_t const &name, size_t win_modulo, money_t prize,
         money_t loss)
      : Square(name), win_modulo(win_modulo), prize(prize), loss(loss) {}
  void action(Player &player) override {
    static size_t counter = 0;
    ++counter;
    counter %= win_modulo;
    if (counter == 0) {
      player.add_money(prize);
    } else {
      player.add_money(-loss);
    }
  }
  void passing_action(Player &player) override { return; }

 private:
  const size_t win_modulo;
  const money_t prize;
  const money_t loss;
};

#endif  // BOOKIE_H