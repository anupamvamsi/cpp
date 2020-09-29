#include <iostream>

using namespace std;

int main() // no need to use return statements in main() - it is a special case function
{
    int numberCats = 5, numberDogs = 4; 
    unsigned int numberCats_ = 5;  // (only positive numbers)
    
    /*  DATATYPE SIZES (CHANGE DEPENDING ON COMPILER) - USE "sizeof()" TO FIND SIZE:
        
        char         .. 1B
        bool         .. 1B

        short        .. 2B
    
        int          .. 4B
        unsigned int .. 4B
        long         .. 4B
        float        .. 4B 
    
        long long    .. 8B
        double       .. 8B 
    */

    /*  DECLARING POINTERS

        int* ptr;
        bool* var = false;

        REFERENCES

        int& variable;
        bool& var = false;
    */
    
    cout << "Number of cats: " << numberCats << "\n";
    cout << "Number of dogs: " << numberDogs << "\n";

    cout << "Total: " << numberDogs + numberCats << "\n";

    cin.get(); // waits for you to press "ENTER"

    return 0; // basically means nothing to a main function
}