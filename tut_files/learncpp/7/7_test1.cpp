#include <cassert>
#include <climits>
#include <iostream>

#include "constants.hpp"

void ignoreLine() {
  std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
}

double calculateHeight(double initialHeight, int seconds) {
  double distanceFallen{constants::grav_accel_constant * seconds * seconds / 2};
  double currentHeight{initialHeight - distanceFallen};

  if (currentHeight < 0.0) {
    return 0.0;
  }

  return currentHeight;
}

void calculateAndPrintHeight(double initialHeight, int time) {
  std::cout << "At " << time << " seconds, the ball is at height: "
            << calculateHeight(initialHeight, time) << "\n";
}

double getInitialHeight() {
  while (true) {
    std::cout << "Enter initial height (in metres): ";
    double initialHeight{};

    std::cin >> initialHeight;

    if (std::cin.fail()) {
      std::cin.clear();
      ignoreLine();
      std::cout << "Error: Invalid input, try again.\n";
    }

    else {
      ignoreLine();
      assert(initialHeight > 0.0 && "Height must be positive.");
      return initialHeight;
    }
  }
}

int getTime() {
  while (true) {
    std::cout
        << "Enter the time (in seconds) until you want to see the ball fall: ";
    int time{};

    std::cin >> time;

    if (std::cin.fail()) {
      std::cin.clear();
      ignoreLine();
      std::cout << "Error: Invalid input, try again.\n";
    }

    else {
      ignoreLine();
      assert(time > 0 && "Time must be positive.");
      return time;
    }
  }
}

int main() {
  int time = getTime();
  float height = getInitialHeight();

  for (int i{0}; i <= time; ++i) {
    calculateAndPrintHeight(height, i);
  }

  return 0;
}