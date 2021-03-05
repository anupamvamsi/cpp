#include <iostream>

#include "utils.hpp"

using namespace std;

// FUNCTION PROTOTYPE
// void printHello();

// WRITING A FUNCTION
void showMenu() {
  cout << "1. Search" << endl;
  cout << "2. View Record" << endl;
  cout << "3. Quit" << endl;
}

// RETURNING VALUES
int getInput() {
  cout << "Enter selection: " << endl;

  int input;  // scope of input is only within the function
  cin >> input;

  return input;
}

// PASSING PARAMETERS
void processSelection(int dummy) {
  switch (dummy) {
    case 1:
      cout << "Searching..." << endl;
      break;
    case 2:
      cout << "Viewing..." << endl;
      break;
    case 3:
      cout << "Quitting..." << endl;
      break;
    default:
      cout << "Please select an item from the menu." << endl;
  }
}

// MAIN FUNCTION
int main() {
  showMenu();
  int selection = getInput();

  processSelection(selection);
  printHello();

  return 0;
}

// DEFINING FUNCTIONS AFTER "main()" FUNCTION
void printHello() { cout << "Hello! :D" << endl; }