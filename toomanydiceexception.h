#ifndef TOO_MANY_DICE_EXCEPTION_H
#define TOO_MANY_DICE_EXCEPTION_H

#include <exception>

class TooManyDiceException : public std::exception {
 public:
  TooManyDiceException() = default;
  ~TooManyDiceException() = default;
};

#endif  // TOO_MANY_DICE_EXCEPTION_H