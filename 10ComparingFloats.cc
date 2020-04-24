#include <iostream>
#include <iomanip>

using namespace std;

int main()
{
    float valueF = 1.1;

    // Comparing values for float using "==": [DOESN'T WORK]
    if (valueF == 1.1)
        cout << "Equal!";
    else
        cout << "Not Equal!";

    // Comparing values for float using "<": [WORKS]
    if (valueF < 1.11)
        cout << "\nEqual.\n";
    else
        cout << "\nNot Equal.\n";

    cout << setprecision(10) << valueF << "\n" << endl;

    return 0;
}