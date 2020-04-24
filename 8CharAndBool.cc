#include <iostream>

using namespace std;

int main()
{
    char cValue = 65; // will print "A"
    cout << cValue << endl;

    bool bValue = true;
    cout << bValue << endl;

    cout << int(cValue) << endl;

    wchar_t wcValue = 150;
    cout << wcValue << endl;
    cout << char(wcValue) << endl;

    return 0;
}