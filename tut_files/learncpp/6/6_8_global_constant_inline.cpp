// https://www.learncpp.com/cpp-tutorial/global-constants-and-inline-variables/

// Best Practices (This file is not to be compiled)
// a_header_file.hpp
// header file start
#pragma once

namespace constants {
inline constexpr int theAnswerToEverything{42};
inline constexpr double pi{3.14};
inline constexpr int electronCharge{-1};
inline constexpr int protonCharge{+1};
}  // namespace constants

// header file ends here

// some_file.cpp
// file start
#include <iostream>

#include "constants.hpp"

int main() {
  std::cout << "Something something, so, " << constants::theAnswerToEverything
            << "\n";

  return 0;
}