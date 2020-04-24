/* Password program
*/

#include <iostream>

using namespace std;

int main()
{
    std::string password = "helloworld";
    std::string input;

    cout << "Enter password > ";
    cin >> input;

    if (input == password)
        cout << "You may pass! \n";
    else
        cout << "You shall not pass! \n";

    return 0;
}