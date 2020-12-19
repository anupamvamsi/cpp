// #include <ctime>
#include "withFiles.h"

#include <fstream>
#include <iostream>
#include <random>
#include <vector>

int prng()  // Pseudo-random Number Generator
{
  std::mt19937_64 mt;
  mt.seed(std::time(0));  // Using ctime for seed - was unable to figure out how
                          // to use random_device for non-repetitive o/p

  // Both 0 and 100 are inclusive
  std::uniform_int_distribution<uint64_t> dist(0, 100);

  int random_num = dist(mt);

  return random_num;
}

void print_vector(std::vector<int> guesses)  // vector is passed by value
{
  if (guesses.size() > 1) {
    std::cout << "Your guesses are: \n";

    // "count-1" so that the last answer isn't printed
    for (int i = 0; i < guesses.size() - 1; i++)
      std::cout << "Guess " << i + 1 << ": " << guesses[i] << std::endl;

    std::cout << "--------------------------------------------------\n";
  }
}

std::vector<int> guesser(int random_num) {
  int guess;
  std::vector<int> guesses;

  while (true) {
    std::cin >> guess;
    guesses.push_back(guess);

    if (guess == random_num) {
      if (guesses.size() == 1) {
        std::cout << "---------------------------------------------------------"
                     "-----\n";
        std::cout << "Woo hoo! First try! ";
        std::cout << guess << " is the correct guess! Congratulations!\n";
        std::cout << "---------------------------------------------------------"
                     "-----\n";
      } else {
        std::cout << "-----------------------------------------\n";
        std::cout << guess
                  << " is the correct guess! Congratulations!\nYou took ";
        std::cout << guesses.size() << " guesses!\n";
        std::cout << "-----------------------------------------\n";
      }
      break;
    } else if (guess > random_num) {
      std::cout << "Too high! Guess again!\n";
    } else {
      std::cout << "Too low! Guess again!\n";
    }
  }

  return guesses;
}

void print_high_score(int num_of_guesses)  // uses files
{
  std::ifstream input("high_score.txt");

  if (!input
           .is_open())  // Checking if 'input' file (high_score.txt) can be read
  {
    std::cout << "ERROR: Unable to read high score file!\n";
    return;
  }

  int high_score;
  input >> high_score;  // 'input' is like 'cin' // inputting the present high
                        // score into 'high_score'
  input.close();

  std::ofstream output("high_score.txt");  // 'output' is like 'cout'

  if (!output.is_open())  // Checking if 'output' file (high_score.txt) can be
                          // opened
  {
    std::cout << "ERROR: Unable to write to high score file!\n";
    return;
  }

  if (num_of_guesses < high_score)  // comparing value in the file to num of
                                    // guesses by the player
  {
    output << num_of_guesses;
    output.close();

    std::ifstream printer("high_score.txt");
    int num;
    printer >> num;

    std::cout << "DING DING DING! NEW HIGH SCORE! ONLY ";
    std::cout << num;  // I had to close the 'output' object for this statement
                       // to work
    std::cout << " GUESSE(S)!\n";
    std::cout << "--------------------------------------------------\n";
    printer.close();
  } else  // so that file contents don't get deleted
    output << high_score;

  output.close();
}

void play_game() {
  int random_num = prng();

  std::cout << "Guess a number between 0 and 100!: \n";
  std::cout << "(Psst! The number lies between " << random_num - 1 << " and "
            << random_num + 1 << "!)\n";

  // If input is a string, guesser program exits
  std::vector<int> player_guesses = guesser(random_num);
  print_vector(player_guesses);
  print_high_score(player_guesses.size());
}

int player_choice() {
  int input;
  std::cin >> input;

  switch (input) {
    case 0:  // Nope I don't
      std::cout << "Aw.\n";
      return 0;

    case 1:  // YES YES YES
      play_game();
      break;
  }
  return 1;
}