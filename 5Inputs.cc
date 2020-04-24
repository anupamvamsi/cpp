#include <iostream>

using namespace std;

int main()
{

    cout << "Enter your name: ";
    string input;
    cin >> input;
    cout << "Hi, " + input + "\n";

    cout << "\nEnter a value! ";
    int value;
    cin >> value;
    cout << "Your value is, " << value << "\n\n";    

    return 0;
}