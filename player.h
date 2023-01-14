#ifndef PLAYER_H
#define PLAYER_H

#include <string>

#include "types.h"

class Player {
 public:
  Player(player_name_t const &name, const money_t money) : name(name), money(money) {}
  virtual ~Player() = default;

 private:
  const player_name_t name;
  money_t money;
};

#endif  // PLAYER_H