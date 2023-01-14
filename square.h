#ifndef SQUARE_H
#define SQUARE_H

#include "types.h"

class Square {
 public:
  Square(square_name_t name) : name(name) {}
  const square_name_t name;

 private:
};

#endif  // SQUARE_H