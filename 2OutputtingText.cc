#include <iostream>

using namespace std;

main() // no need to use return statements, main() will assume 0 is being returned
{
    cout << "This is some text\n" << flush;
    cout << "whattay. " << "whatty. " << "eeee.\n";
    cout << "Hey!\n";
    cout << "What's this?\n\n";

    cin.get(); // waits for you to press "ENTER"

    return 0; // doesn't make any difference if this statement exists or not here
}