#include <iostream>

using namespace std;

int main()
{
    // ANIMALS, ANIMALS, JUST LIKE ANIMALS, ANIMALS-MALS. AH-OOOOOOUUUUUUUU!
    string animals[2][3] = {
        {"fox", "dog", "cat"},
        {"mouse", "squirrel", "parrot"}};

    for (int i = 0; i < 2; i++)
    {
        for (int j = 0; j < 3; j++)
        {
            cout << "Animal in " << i + 1 << "x" << j + 1 << " is " << animals[i][j] << "\t";
        }
        cout << "\n";
    }

    // MULTIPLICATION TABLE - FIRST ROW NUMBER NEEDN'T BE SPECIFIED
    int mulTable[10][10] = {0};

    for (int i = 0; i < 10; i++)
    {
        cout << "Table of " << i + 1 << "\n";
        cout << "==========="
             << "\n";
        for (int j = 0; j < 10; j++)
        {
            mulTable[i][j] = (i + 1) * (j + 1);
            cout << i + 1 << " x " << j + 1 << " = " << mulTable[i][j] << "\n";
        }
        cout << "\n";
    }
}