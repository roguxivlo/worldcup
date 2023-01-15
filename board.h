#ifndef BOARD_H
#define BOARD_H

#include "bookie.h"
#include "goal.h"
#include "match.h"
#include "notraining.h"
#include "penalty.h"
#include "start.h"
#include "types.h"
#include "yellowcard.h"

// TODO: advance method!!

class Board {
 public:
  Square* advance(const Player* player) {}
  Square* get_square(size_t position) { return &squares[position]; }
  size_t get_n_squares() const { return N_SQUARES; }

 private:
  static const size_t N_SQUARES = 12;
  players_positions_t players_positions;
  const square_list_t squares = {
      Start("Początek sezonu", 50),
      Match("Mecz z San Marino", 160, Match::FRIENDLY),
      NoTraining("Dzień wolny od treningu"),
      Match("Mecz z Liechtensteinem", 220, Match::FRIENDLY),
      YellowCard("Żółta kartka", 3),
      Match("Mecz z Meksykiem", 300, Match::GROUP_STAGE),
      Match("Mecz z Arabią Saudyjską", 280, Match::GROUP_STAGE),
      Bookie("Bukmacher", 3, 300, 300),
      Match("Mecz z Argentyną", 250, Match::GROUP_STAGE),
      Goal("Gol", 120),
      Match("Mecz z Francją", 400, Match::FINAL),
      Penalty("Rzut karny", 180)};
};

#endif  // BOARD_H