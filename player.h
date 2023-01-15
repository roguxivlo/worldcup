#ifndef PLAYER_H
#define PLAYER_H

#include <string>
#include <memory>

#include "types.h"
#include "worldcup.h"

class Square;
class Board;

class Player {
public:
    static const size_t PLAYING = 0;
    static const size_t SUSPENDED = 1;
    static const size_t BANKRUPT = 2;

    Player(player_name_t const &name, money_t money) ;

    void add_money(money_t amount);

    void suspend(size_t suspension);

    money_t get_money() const;

    std::shared_ptr<Square> play_round(std::shared_ptr<Die> *dice, Board &board);

    player_name_t get_name() const;

    size_t get_status() const;

    std::string status_to_string() const;

private:
    const player_name_t name;
    money_t money;
    size_t status = PLAYING;
    size_t suspension_time = 0;
    size_t position = 0;
};

#endif  // PLAYER_H