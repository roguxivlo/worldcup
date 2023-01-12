#ifndef TOO_FEW_DICE_EXCEPTION_H
#define TOO_FEW_DICE_EXCEPTION_H

#include <exception>

class TooFewDiceException : public std::exception {
 public:
  TooFewDiceException() = default;
  ~TooFewDiceException() = default;
};

#endif // too_few_dice_exception_h