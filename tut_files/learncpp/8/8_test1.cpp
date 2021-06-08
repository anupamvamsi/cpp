#include <cassert>
#include <climits>
#include <iostream>

void ignoreLine() {
  std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
}

struct Fraction {
  int numerator{};
  int denominator{};
};

Fraction getFraction() {
  Fraction f{};

  std::cout << "Enter numerator: ";
  std::cin >> f.numerator;
  ignoreLine();

  std::cout << "Enter denominator: ";
  std::cin >> f.denominator;
  assert(f.denominator != 0 && "Enter non-zero denominator.\n");
  ignoreLine();

  return f;
}

void multiplyAndPrint(Fraction f1, Fraction f2) {
  Fraction f{};

  f.numerator = f1.numerator * f2.numerator;
  f.denominator = f1.denominator * f2.denominator;

  std::cout << "Result of " << f1.numerator << "/" << f1.denominator
            << " multiplied with " << f2.numerator << "/" << f2.denominator
            << " is: " << f.numerator << "/" << f.denominator << " ("
            << static_cast<double>(f.numerator) / f.denominator << ").\n";
}

struct AdStats {
  int numShown{};              // to users
  double percentageClicked{};  // by users
  double avgEarnings{};        // from ads that were clicked
};

void printAndCalculateAdRevenue(AdStats stats) {
  std::cout << "Ads shown: " << stats.numShown
            << ", Percentage clicked: " << stats.percentageClicked
            << ", Average earnings: $" << stats.avgEarnings << ".\n";

  std::cout << "Total revenue: $"
            << stats.numShown * stats.percentageClicked / 100 *
                   stats.avgEarnings
            << '\n';
}

AdStats getAdStats() {
  AdStats stats{};

  std::cout << "Enter stats:\n";
  std::cout << "Number of ads shown: ";
  std::cin >> stats.numShown;
  assert(stats.numShown >= 0 && "Number of ads shown cannot be negative.");
  ignoreLine();

  std::cout << "Percentage of ads clicked by users: ";
  std::cin >> stats.percentageClicked;
  assert(stats.percentageClicked >= 0 &&
         "Percentage of ads clicked has to be positive.");
  ignoreLine();

  std::cout << "Average earnings from clicked ads: ";
  std::cin >> stats.avgEarnings;
  assert(stats.avgEarnings >= 0 && "Earnings cannot be negative.");
  ignoreLine();

  return stats;
}

int main() {
  printAndCalculateAdRevenue(getAdStats());

  Fraction f1{}, f2{};
  f1 = getFraction();
  f2 = getFraction();

  multiplyAndPrint(f1, f2);

  return 0;
}