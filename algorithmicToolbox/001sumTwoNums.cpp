#include <iostream>

int sumTwoNum(int fNum, int sNum) 
{
    return fNum + sNum;
}

int main() 
{
    int fNum = 0;
    int sNum = 0;
    std::cin >> fNum;
    std::cin >> sNum;
    std::cout << sumTwoNum(fNum, sNum);
    return 0;
}