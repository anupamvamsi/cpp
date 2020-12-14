// Building this app based on the Cpp tutorials by Caleb Curry on YT.
// Find the playlist here: https://www.youtube.com/playlist?list=PL_c9BZzLwBRJVJsIfe97ey45V4LP_HXiG

#include <string>
#include <iostream>
#include <random>   // In line with the C+11 standard
#include <ctime>

/*
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

void play_game()
{
    // Random Number Generation:
    /* Tried using random_device for seeding the random function
        std::random_device seed;    // Non-deterministic seed
        std::mt19937_64 mt(seed()); // [0, 2^64) 64-bit mersenne-twister engine with random_device seed
    */
    std::mt19937_64 mt;
    mt.seed(std::time(0)); // Using ctime for seed - was unable to figure out how to use random_device for non-repetitive o/p

    std::uniform_int_distribution<uint64_t> dist(0, 250); // Both 0 and 100 are inclusive

    int random_num = dist(mt);  // Storing the random num
    
    std::cout << "Random number is...\n" << random_num << "!\n";
    std::cin.get(); // Wait for Enter/Return key

    std::cout << "Game is starting... Please wait...\n";
}

int main()
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
            std::cout << "You want to play, yay!\n";
            play_game();
            break;
            
        default: // Ugh, what?
            std::cout << "Enter a valid input, 0 or 1!\n";
            break;
        } 
    } while(input != 1); // Infinite loop starts if strings are given as input - need to fix
}