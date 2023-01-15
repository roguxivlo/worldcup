#include "player.h"
#include "types.h"
#include "square.h"
#include "board.h"

Player::Player(player_name_t const &name, money_t money) : name(name), money(money) {}

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

money_t Player::get_money() const {
    return money;
}

std::shared_ptr<Square> Player::play_round(size_t moves, Board &board) {
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
            square = board.get_square(position).get();
            square->passing_action(*this);
            if (status == BANKRUPT) {
                return nullptr; // TODO syf
            }
        }
        position++;
        position %= board.get_n_squares();
        square = board.get_square(position).get();
        square->action(*this);
    }
    return board.get_square(position);
}

player_name_t Player::get_name() const {
    return name;
}

std::string Player::get_status() const {
    if (status == PLAYING) {
        return "w grze";
    } else if (status == BANKRUPT) {
        return "*** bankrut ***";
    } else {
        return "*** czekanie: " + std::to_string(suspension_time) + " ***";
    }
}