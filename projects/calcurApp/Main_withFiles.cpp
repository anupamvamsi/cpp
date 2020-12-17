// Building this app based on the Cpp tutorials by Caleb Curry on YT.
// Find the playlist here: https://www.youtube.com/playlist?list=PL_c9BZzLwBRJVJsIfe97ey45V4LP_HXiG
#include <iostream>
#include <vector>
#include <fstream>
#include <random>
#include <ctime>
#include <string>

/*  Why not to use rand()
	Don't use this for using rand()! 
	Don't use rand() anymore!
	According to C++11 standard, it is recommended to use <random>.
	rand() has a bunch of issues, including being biased. 
	
	To read more, go to: https://stackoverflow.com/questions/19553265/how-does-modulus-and-rand-work
	To find the discussion by STL: https://channel9.msdn.com/Events/GoingNative/2013/rand-Considered-Harmful
	DON'T DO `rand() % x`!

	Extra: DON'T USE `NULL`. USE `nullptr`.

	#include <cstdlib>  // for rand num gen
	#include <ctime>    // for rand num gen
*/

int prng() // Pseudo-random Number Generator
{
	std::mt19937_64 mt;
	mt.seed(std::time(0)); // Using ctime for seed - was unable to figure out how to use random_device for non-repetitive o/p

	std::uniform_int_distribution<uint64_t> dist(0, 100); // Both 0 and 100 are inclusive

	int random_num = dist(mt);
	
	return random_num;
}

void print_vector(std::vector<int> guesses) // vector is passed by value
{
	if (guesses.size() > 1)
	{
		std::cout << "Your guesses are: \n";

		for (int i=0; i < guesses.size()-1; i++) // "count-1" so that the last answer isn't printed
			std::cout << "Guess " << i+1 << ": " << guesses[i] << std::endl;
		std::cout << "--------------------------------------------------\n";
	}
}

std::vector<int> guesser(int random_num)
{
	int guess;
	std::vector<int> guesses;

	while (true)
	{
		std::cin >> guess;
		guesses.push_back(guess);

		if (guess == random_num)
		{   
			if (guesses.size() == 1)
			{
				std::cout << "--------------------------------------------------------------\n";
				std::cout << "Woo hoo! First try! ";
				std::cout << guess << " is the correct guess! Congratulations!\n";
				std::cout << "--------------------------------------------------------------\n";
			}
			else
			{
				std::cout << "-----------------------------------------\n";
				std::cout << guess << " is the correct guess! Congratulations!\nYou took ";
				std::cout << guesses.size() << " guesses!\n";
				std::cout << "-----------------------------------------\n";
			}
			break;
		}
		else if (guess > random_num)
		{
			std::cout << "Too high! Guess again!\n";
		}
		else
		{
			std::cout << "Too low! Guess again!\n";
		}
	}
	
	return guesses;
}

void print_high_score(int num_of_guesses) // uses files
{
	std::ifstream input ("high_score.txt");
	
	if (!input.is_open()) // Checking if 'input' file (high_score.txt) can be read
	{
		std::cout << "ERROR: Unable to read high score file!\n";
		return;
	}

	int high_score;
	input >> high_score;    // 'input' is like 'cin' // inputting the present high score into 'high_score'
	input.close();

	std::ofstream output ("high_score.txt"); // 'output' is like 'cout' 
	
	if (!output.is_open()) // Checking if 'output' file (high_score.txt) can be opened
	{
		std::cout << "ERROR: Unable to write to high score file!\n";
		return;
	}

	if (num_of_guesses < high_score) // comparing value in the file to num of guesses by the player
	{
		output << num_of_guesses;
		output.close();
		
		std::ifstream printer ("high_score.txt");
		int num;
		printer >> num;

		std::cout << "DING DING DING! NEW HIGH SCORE! ONLY ";
		std::cout << num; // I had to close the 'output' object for this statement to work
		std::cout << " GUESSE(S)!\n";
		std::cout << "--------------------------------------------------\n";
		printer.close();
	}
	else // so that file contents don't get deleted
		output << high_score;
	
	output.close();
}

void play_game()
{   
	int random_num = prng();

	std::cout << "Guess a number between 0 and 100!: \n";
	std::cout << "(Psst! The number lies between " << random_num - 1 << " and " << random_num + 1 << "!)\n";

	std::vector<int> player_guesses = guesser(random_num); // If input is a string, guesser program exits
	print_vector(player_guesses);
	print_high_score(player_guesses.size());
}

int player_choice()
{
	int input;
	std::cin >> input;
	
	switch (input)
	{
		case 0: // Nope I don't
			std::cout << "Aw.\n";
			return 0;    
		
		case 1: // YES YES YES
			play_game();
			break;
	}
	return 1;       
}

int main() // Run/Start the game
{
	std::ofstream output; // opening the file for initializing default high score
	output.open("high_score.txt"); // in case the file doesn't exist
	output << 101; // default high score every time program is run
	output.close();
	
	int choice;
	std::cout << "\nDo you wanna build a snowmannn?!\n";
	std::cout << "0. Nope, I don't!" << std::endl << "1. YES, YES, YES!" << "\n\n";

	if (player_choice() != 0)
	{
		do
		{
			std::cout << "\nKeep playing?\n";
			std::cout << "0. Nah, I'm tired." << std::endl << "1. Oh sure, why not?" << "\n\n";

			choice = player_choice();    
		} while (choice != 0);
	}

	std::remove("high_score.txt"); // delete the high score file after program ends
}