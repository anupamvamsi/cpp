// https://www.codewars.com/kata/562f91ff6a8b77dfe900006e

#include <cmath>
#include <iostream>

class Movie {
 public:
  static void movie(double card, double ticket, double perc);
};

void Movie::movie(double card, double ticket, double percent) {
  double systemACost{}, systemBCost{card}, systemBTicket{ticket};
  int countUntilSystemBIsCheaper{};

  while (true) {
    if (std::ceil(systemBCost) < systemACost) {
      std::cout << "A: " << systemACost << ", B: " << std::ceil(systemBCost)
                << "\n";
      std::cout << "Count: " << countUntilSystemBIsCheaper << "\n";
      break;
    }
    ++countUntilSystemBIsCheaper;

    systemBTicket *= percent;
    systemBCost += systemBTicket;
    systemACost += ticket;
  }
}

int main() {
  Movie::movie(500, 15, 0.9);
  Movie::movie(100, 10, 0.95);
  Movie::movie(6190, 21, 0.55);
  Movie::movie(914, 4, 0.7);

  return 0;
}