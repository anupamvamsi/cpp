#include <iostream>

using namespace std;

int main()
{
    int value;

    cout << sizeof(value) << endl;

    // ONE-DIMENSIONAL ARRAY
    int values[] = {4, 7, 3, 4};

    cout << sizeof(values) << endl;
    cout << sizeof(int) << endl;

    // "count" VALUE IS ALLOCATED BY CALCULATIONS THROUGH "sizeof()"
    for (int i = 0; i < sizeof(values) / sizeof(int); i++)
    {
        cout << values[i] << " " << endl;
    }

    // TWO-DIMENSIONAL ARRAY
    int twoDim[3][4] = {
        {1, 2, 3, 4},
        {5, 6, 7, 8},
        {9, 10, 11, 12}};

    // cout << sizeof(twoDim) / sizeof(twoDim[0]) << endl;
    // cout << sizeof(twoDim[0]) / sizeof(int) << endl;

    cout << "Matrix is: " << endl;

    // USING "sizeof()" TO GENERALISE SIZE OF A TWO-DIMENSIONAL ARRAY
    for (int i = 0; i < sizeof(twoDim) / sizeof(twoDim[0]); i++)
    {
        for (int j = 0; j < sizeof(twoDim[0]) / sizeof(int); j++)
        {
            cout << twoDim[i][j] << "\t";
        }
        cout << "\n";
    }
    cout << endl;
}