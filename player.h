#ifndef PLAYER_H
#define PLAYER_H

#include <string>

#include "types.h"

class Player {
 public:
  static const size_t SUSPENDED = 1;
  static const size_t PLAYING = 0;
  static const size_t BANCRUPT = 2;
  static const std::string PLAYING_STR;
  static const std::string BANCRUPT_STR;
  static const std::string SUSPENDED_STR;
  Player(player_name_t const &name, money_t money) : name(name), money(money) {}
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

  money_t get_money() const { return money; }

  Square *play_round(size_t moves, Board &board) {
    if (status == SUSPENDED) {
      if (suspension_time == 0) {
        status = PLAYING;
      } else {
        --suspension_time;
      }
    } else if (status == PLAYING) {
      Square *square;
      for (size_t i = 0; i < moves - 1; ++i) {
        position++;
        position %= board.get_n_squares();
        square = board.get_square(position);
        square->passing_action(*this);
        if (status == BANCRUPT) {
          return;
        }
      }
      position++;
      position %= board.get_n_squares();
      square = board.get_square(position);
      square->action(*this);
    }
    return board.get_square(position);
  }

  player_name_t get_name() const { return name; }

  std::string get_status() {
    if (status == PLAYING) {
      return PLAYING_STR;
    } else if (status == BANCRUPT) {
      return BANCRUPT_STR;
    } else {
      return SUSPENDED_STR + std::to_string(suspension_time) + " ***";
    }
  }

 private:
  const player_name_t name;
  money_t money;
  size_t status = PLAYING;
  size_t suspension_time = 0;
  size_t position = 0;
};

const std::string Player::PLAYING_STR = "w grze";

const std::string Player::BANCRUPT_STR = "*** bankrut ***";

const std::string Player::SUSPENDED_STR = "*** czekanie: ";

#endif  // PLAYER_H