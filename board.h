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

class Board {
 public:
 private:
  static const size_t N_SQUARES = 12;
  const square_list_t squares = {
      Start("Początek sezonu"),
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