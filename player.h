#ifndef PLAYER_H
#define PLAYER_H

#include <string>

#include "types.h"

class Player {
 public:
  static const size_t SUSPENDED = 1;
  static const size_t PLAYING = 0;
  static const size_t BANCRUPT = 2;
  Player(player_name_t const &name, const money_t money)
      : name(name), money(money) {}
  void add_money(const money_t amount) {
    money += amount;
    if (money < 0) {
      money = 0;
      status = BANCRUPT;
    }
  }
  void suspend(const size_t suspension) {
    status = SUSPENDED;
    suspension_time = suspension;
  }

  void play_round(size_t moves, Board* board) {
    if (status == SUSPENDED) {
      if (suspension_time == 0) {
        status = PLAYING;
      } else {
        --suspension_time;
      }
    }
    if (status == PLAYING) {
      Square *square;
      for (size_t i = 0; i < moves - 1; ++i) {
        square = board->advance(this);
        square->passing_action(*this);
        if (status == BANCRUPT) {
          return;
        }
      }
      square = board->advance(this);
      square->action(*this);
    }
  }

 private:
  const player_name_t name;
  money_t money;
  size_t status = PLAYING;
  size_t suspension_time = 0;
};

#endif  // PLAYER_H