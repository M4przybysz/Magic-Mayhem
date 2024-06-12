// Local Headers
#include "../include/Card.hpp"

// C++ Headers
#include <algorithm>

Card::Card() {
    cost_ = 1;
}
Card::Card(const int& cost) : cost_(cost) {
   
}
