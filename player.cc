#include "player.h"

#include <iostream>

#include "board.h"
#include "square.h"
#include "types.h"

Player::Player(player_name_t const &name, money_t money)
    : name(name), money(money) {}

void Player::add_money(const money_t amount) {
  money += amount;
  if (money < 0) {
    money = 0;
    status = BANKRUPT;
  }
}

void Player::suspend(const size_t suspension) {
  status = SUSPENDED;
  suspension_time = suspension;
}

money_t Player::get_money() const { return money; }

std::shared_ptr<Square> Player::play_round(std::shared_ptr<Die> *dice, Board &board) {
  std::cerr << name << " plays round" << std::endl;
  if (status == SUSPENDED) {
    std::cerr << name << " is suspended" << std::endl;
    --suspension_time;
    if (suspension_time == 0) {
      std::cerr << name << " is no longer suspended" << std::endl;
      status = PLAYING;
    }
  }
  if (status == PLAYING) {
    size_t moves = dice[0]->roll() + dice[1]->roll();
    std::cerr << name << " is playing, has: " << moves << " moves" << std::endl;
    Square *square;
    if (moves > 0) {
      for (size_t i = 0; i < moves - 1; ++i) {
        ++position;
        position %= board.get_n_squares();
        if (status != BANKRUPT) {
          square = board.get_square(position).get();
          square->passing_action(*this);
        }
      }
      ++position;
      position %= board.get_n_squares();
    }

    if (status != BANKRUPT) {
      square = board.get_square(position).get();
      square->action(*this);
    }
  }
  return board.get_square(position);
}

player_name_t Player::get_name() const { return name; }

size_t Player::get_status() const { return status; }

std::string Player::status_to_string() const {
  if (status == PLAYING) {
    return "w grze";
  } else if (status == BANKRUPT) {
    return "*** bankrut ***";
  } else {
    return "*** czekanie: " + std::to_string(suspension_time) + " ***";
  }
}