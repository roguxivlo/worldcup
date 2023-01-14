#ifndef NO_TRAINING_H
#define NO_TRAINING_H

#include "square.h"
#include "types.h"

class NoTraining : public Square {
 public:
  NoTraining(square_name_t const &name) : Square(name) {}
};

#endif  // NO_TRAINING_H