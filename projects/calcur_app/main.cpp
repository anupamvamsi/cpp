// Building this app based on the Cpp tutorials by Caleb Curry on YT.
// Find the playlist here:
// https://www.youtube.com/playlist?list=PL_c9BZzLwBRJVJsIfe97ey45V4LP_HXiG

#include <ctime>
#include <iostream>
#include <random>  // In line with the C+11 standard
#include <string>

/*
        Don't use this for using rand()!
        Don't use rand() anymore!
        According to C++11 standard, it is recommended to use <random>.
        rand() has a bunch of issues, including being biased.

        To read more, go to:
   https://stackoverflow.com/questions/19553265/how-does-modulus-and-rand-work
        To find the discussion by STL:
   https://channel9.msdn.com/Events/GoingNative/2013/rand-Considered-Harmful
        DON'T DO `rand() % x`!
        Extra: DON'T USE `NULL`. USE `nullptr`.
        #include <cstdlib>  // for rand num gen
        #include <ctime>    // for rand num gen
*/

int player_choice();
int prng();
int guesser(int);
void play_game();

int _random_num = prng();

int main()  // Run/Start the game
{
  play_game();
}

int player_choice() {
  std::cout << "\nDo you wanna build a snowmannn?!\n";
  std::cout << "0. Nope, I don't!" << std::endl
            << "1. YES, YES, YES!"
            << "\n\n";

  int input;
  std::cin >> input;

  switch (input) {
    case 0:  // Nope I don't
      std::cout << "Aw.\n";
      return -1;

    case 1:  // YES YES YES
      std::cout << "You want to play, yay!\n";
      return 0;

    default:  // Ugh, what?
      std::cout << "Enter a valid input, 0 or 1!\n";
      return -2;
  }

  return -1;
}

int prng()  // Psuedo-random Number Generator
{
  // Random Number Generation:
  /* Tried using random_device for seeding the random function
          std::random_device seed;    // Non-deterministic seed
          std::mt19937_64 mt(seed()); // [0, 2^64) 64-bit mersenne-twister
     engine with random_device seed
  */
  std::mt19937_64 mt;
  mt.seed(std::time(0));  // Using ctime for seed - was unable to figure out how
                          // to use random_device for non-repetitive o/p

  std::uniform_int_distribution<uint64_t> dist(
      0, 100);  // Both 0 and 100 are inclusive

  _random_num = dist(mt);  // Storing the random num

  return _random_num;
  // std::cout << "Game is starting... Please wait...\n";
}

int guesser(int _random_num)  // Guesser logic
{
  int guess;

  std::cout << "Guess a number between 0 and 100!: \n";
  std::cout << "(Psst! The random number lies between " << _random_num - 1
            << " and " << _random_num + 1 << "!)\n";
  std::cin >> guess;

  // If input is a string, program exits
  if (guess == _random_num) {
    std::cout << "Correct guess! Congratulations!\n";
    return -1;
  } else if (guess > _random_num) {
    std::cout << "Too high! Guess again!\n";
    return 0;
  } else {
    std::cout << "Too low! Guess again!\n";
    return 0;
  }
}

void play_game()  // Keep playing
{
  int flag1, flag2;
  // flag1 = player_choice();
  do {
    flag1 = player_choice();
    if (flag1 == -1)       // Input is 0
      break;               // exit game
    else if (flag1 == -2)  // Invalid input is entered
    {
      while (flag1 == -2)  // If invalid input continues
        flag1 = player_choice();
      if (flag1 == -1)  // Input is 0
        break;          // exit game
      flag2 = guesser(_random_num);
    } else
      flag2 = guesser(_random_num);  // Don't call prng() again since new random
                                     // num would be generated

  } while (flag2 != -1);  // Infinite loop starts if strings are given as input
                          // - need to fix // IS FIXED
}