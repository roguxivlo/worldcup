#ifndef MATCH_H
#define MATCH_H

#include "square.h"
#include "types.h"
#include <iostream>

class Match : public Square {
public:
    constexpr static const match_weight_t FRIENDLY = 1;
    constexpr static const match_weight_t GROUP_STAGE = 2.5;
    constexpr static const match_weight_t FINAL = 4;

    Match(square_name_t const &name, money_t match_fee, match_weight_t weight)
            : Square(name), match_fee(match_fee), weight(weight) {}

    void action(Player &player) override {
        std::cout << player.get_name()<<" played match: "<<name<<" and got paid: "<< fee_sum <<std::endl;
        player.add_money(fee_sum);
        fee_sum = 0;
    }

    void passing_action(Player &player) override {
        std::cout << player.get_name()<<" passed match: "<<name<<" and paid: "<< match_fee * weight <<std::endl;
        fee_sum += match_fee * weight;
        player.add_money(-match_fee * weight);
    }

private:
    const money_t match_fee;
    const match_weight_t weight;
    money_t fee_sum = 0;
};

#endif  // MATCH_H