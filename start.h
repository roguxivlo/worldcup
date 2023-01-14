#ifndef START_H
#define START_H

#include "square.h"
#include "types.h"

class Start : public Square {
  public:
    Start(square_name_t const &name) : Square(name) {}
};

#endif  // START_H