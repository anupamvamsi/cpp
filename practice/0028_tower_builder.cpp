// https://www.codewars.com/kata/576757b1df89ecf5bd00073b
#include <iostream>
#include <string>
#include <vector>

class Kata {
 public:
  std::vector<std::string> towerBuilder(int nFloors) {
    std::vector<std::string> tower;
    std::string line;

    for (int i{0}; i < nFloors; i++) {
      line = "";
      int num_stars = (2 * nFloors) - 1;

      for (int j{0}; j < num_stars; j++) {
        int star_center = num_stars / 2;  // is also equal to "nFloors - 1"

        if (j + i < star_center || j - i > star_center) {
          line += " ";
        } else {
          line += "*";
        }
      }

      std::cout << line << "\n";
      tower.push_back(line);
    }

    return tower;
    // What is this?
    // return std::vector<std::string>();
  }
};

int main() {
  Kata k;
  int n;

  std::cout << "Enter number of towers you want to build: ";
  std::cin >> n;

  while (n > 0) {
    std::cout << "Tower of " << n << ":\n";
    k.towerBuilder(n--);
  }

  return 0;
}

// Have to figure out the following stuff:
// Following contents are from the file "./tests.cpp", included from "main.cpp":

/* Describe(Tests)
{
    It(ExampleTest1)
    {
        std::vector<std::string> expected = { "*" };

        Kata kata;
        std::vector<std::string> actual = kata.towerBuilder(1);

        Assert::That(actual, Is().EqualTo(expected));
    }

    It(ExampleTest2)
    {
        std::vector<std::string> expected = { " * ", "***" };

        Kata kata;
        std::vector<std::string> actual = kata.towerBuilder(2);

        Assert::That(actual, Is().EqualTo(expected));
    }

    It(ExampleTest3)
    {
        std::vector<std::string> expected = { "  *  ", " *** ", "*****" };

        Kata kata;
        std::vector<std::string> actual = kata.towerBuilder(3);

        Assert::That(actual, Is().EqualTo(expected));
    }
};
*/