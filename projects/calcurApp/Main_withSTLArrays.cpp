// Building this app based on the Cpp tutorials by Caleb Curry on YT.
// Find the playlist here: https://www.youtube.com/playlist?list=PL_c9BZzLwBRJVJsIfe97ey45V4LP_HXiG
#include <iostream>
#include <array>
#include <random>
#include <ctime>

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

void print_STL_Array(std::array<int, 6> guesses, int count) // array is passed by value // only allowing SIX guesses
{
    if (count > 1)
    {
        std::cout << "Your guesses are: \n";

        for (int i=0; i < count-1; i++) // "count-1" so that the last answer isn't printed
            std::cout << "Guess " << i+1 << ": " << guesses[i] << std::endl;
        std::cout << "-----------------------------------------\n";
    }
}

void guesser(int random_num)
{
    int guess, count;
    std::array<int, 6> guesses; // allowing ONLY 6 guesses

    while (true)
    {
        std::cin >> guess;
        guesses[count++] = guess;

        if (guess == random_num)
        {   
            if (count == 1)
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
                std::cout << count << " guesses!\n";
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

    print_STL_Array(guesses, count);
}

void play_game()
{   
    int random_num = prng();

    std::cout << "Guess a number between 0 and 100!: \n";
    std::cout << "(Psst! The number lies between " << random_num - 1 << " and " << random_num + 1 << "!)\n";

    // If input is a string, guesser program exits
    guesser(random_num);
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
        }while (choice != 0);
    }
}