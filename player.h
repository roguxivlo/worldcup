#ifndef PLAYER_H
#define PLAYER_H

#include <string>

class Player {
 public:
  Player(std::string const &name, const int money) : name(name), money(money) {}
  virtual ~Player() = default;

 private:
  std::string name;
  int money;
};

#endif  // PLAYER_H