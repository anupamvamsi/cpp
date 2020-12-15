// Building this app based on the Cpp tutorials by Caleb Curry on YT.
// Find the playlist here: https://www.youtube.com/playlist?list=PL_c9BZzLwBRJVJsIfe97ey45V4LP_HXiG
#include <iostream>
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

void play_game()
{
    int random_num = prng();

    std::cout << "Guess a number between 0 and 100!: \n";
    std::cout << "(Psst! The number lies between " << random_num - 1 << " and " << random_num + 1 << "!)\n";

    // If input is a string, program exits
    while (true)
    {
        int guess;
        std::cin >> guess;

        if (guess == random_num)
        {
            std::cout << "Correct guess! Congratulations!\n";
            std::cout << "-------------------------------\n";
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
}

int main() // Run/Start the game
{
    int input;
    do
    {
        std::cout << "\nDo you wanna build a snowmannn?!\n";
        std::cout << "0. Nope, I don't!" << std::endl << "1. YES, YES, YES!" << "\n\n";

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
    } while(input != 0);
}