#include <iostream>

using namespace std;

int main()
{
    // 'string' is an object of the 'std' namespace
    std::string text1 = "Hello World, it is a nice day!";
    string text2 = " Don't you think so, Fred? :D\n";
    string text3 = text1 + text2;

    cout << text3;

    cin.get();
}