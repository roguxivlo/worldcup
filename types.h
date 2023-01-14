#ifndef TYPES_H
#define TYPES_H

#include <vector>

#include "square.h"
#include "player.h"

using money_t = unsigned int;
using square_list_t = std::vector<Square>;
using square_name_t = std::string;
using player_list_t = std::list<Player>;
using player_name_t = std::string;

#endif  // TYPES_H