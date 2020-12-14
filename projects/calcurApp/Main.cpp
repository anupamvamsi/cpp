// Building this app based on the Cpp tutorials by Caleb Curry on YT.
// Find the playlist here: https://www.youtube.com/playlist?list=PL_c9BZzLwBRJVJsIfe97ey45V4LP_HXiG

#include <iostream>

int main()
{
    int input;
    do
    {
        std::cout << "\nDo you wanna build a snowmannn?!\n" << std::endl << "0. YES, YES, YES!" << std::endl << "1. Nope, I don't!" << "\n\n";
        std::cin >> input;

        switch (input)
        {
        case 0:
            std::cout << "Yay!\n";
            break;
        
        case 1:
            std::cout << "Aw.\n";
            break;
            
        default:
            std::cout << "Enter a valid input, 0 or 1!\n";
            break;
        } 
    } while(input != 1); // Infinite loop starts if strings are given as input
}