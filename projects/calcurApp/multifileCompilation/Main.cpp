// Building this app based on the Cpp tutorials by Caleb Curry on YT.
// Find the playlist here:
// https://www.youtube.com/playlist?list=PL_c9BZzLwBRJVJsIfe97ey45V4LP_HXiG
#include <fstream>
#include <iostream>

#include "withFiles.h"

// This code uses files in C++.

int main()  // Run/Start the game
{
  std::ofstream output;  // opening the file for initializing default high score
  output.open("high_score.txt");  // in case the file doesn't exist
  output << 101;  // default high score every time program is run
  output.close();

  int choice;
  std::cout << "\nDo you wanna build a snowmannn?!\n";
  std::cout << "0. Nope, I don't!" << std::endl
            << "1. YES, YES, YES!"
            << "\n\n";

  if (player_choice() != 0) {
    do {
      std::cout << "\nKeep playing?\n";
      std::cout << "0. Nah, I'm tired." << std::endl
                << "1. Oh sure, why not?"
                << "\n\n";

      choice = player_choice();
    } while (choice != 0);
  }

  // delete the high score file after program ends
  std::remove("high_score.txt");
}