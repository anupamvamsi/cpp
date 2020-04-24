#include <iostream>
#include <iomanip> // for input output manipulation

using namespace std;

int main()
{
    float num1 = 23.4;
    double num2 = 23.4;
    long double num3 = 23.4;

    cout << sizeof(float) << "\n";
    cout << num1 << "\n";
    cout << scientific << num1 << "\n";
    cout << setprecision(30) << fixed << num1 << "\n";
    cout << "\n";

    cout << sizeof(double) << "\n";
    cout << num2 << "\n";
    cout << scientific << num2 << "\n";
    cout << setprecision(30) << fixed << num2 << "\n";
    cout << fixed << num2 << "\n";
    cout << "\n";

    cout << sizeof(long double) << "\n";
    cout << num3 << "\n";
    cout << scientific << num3 << "\n";
    cout << setprecision(30) << fixed << num3 << "\n";
    cout << fixed << num3 << "\n";
    cout << "\n";
    
    return 0;
}