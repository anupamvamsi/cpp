#include <iostream>
#include <limits>
#include <vector>

void PrintTwoDVec(std::vector<std::vector<int>> two_d)
{
    for (std::vector<int> row : two_d)
    {
        for (int element : row)
        {
            std::cout << element << " ";
        }
        std::cout << "\n";
    }
}

void PrintHourGlassMax(int max_idx, std::vector<std::vector<int>> hour_glasses)
{
    std::vector<int> vec = hour_glasses[max_idx];
    for (int i = 0; i < vec.size(); i++)
    {
        if (i < 3)
        {
            std::cout << vec[i] << " ";
        }
        else if (i == 3)
        {
            std::cout << "\n  " << vec[i] << "\n";
        }
        else
        {
            std::cout << vec[i] << " ";
        }
    }
}

int main()
{
    std::vector<std::vector<int>> arr(6), hgs;

    std::cout << "Enter the 2D array:\n";
    for (int i = 0; i < 6; i++)
    {
        arr[i].resize(6);

        for (int j = 0; j < 6; j++)
        {
            std::cin >> arr[i][j];
        }

        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
    }

    // PrintTwoDVec(arr);

    int curr_hg_sum = 0; // hg = hourglass

    // BUG FIXED: Initialized 'max_idx' to 0
    // Seg fault NO LONGER occurs when the following test case is run:
    // Input 2D array:
    /*
     * 1 1 1 0 0 0
     * 0 1 0 0 0 0
     * 1 1 1 0 0 0
     * 0 0 0 0 0 0
     * 0 0 0 0 0 0
     * 0 0 0 0 0 0
    */
    int max = 0, max_idx = 0, count = 0;
    std::vector<int> hg_sums;

    for (int r = 0; r < arr.size(); r++)
    {
        for (int c = 0; c < arr[r].size(); c++)
        {

            if (c + 2 < arr[r].size() && r + 2 < arr.size())
            {
                hgs.push_back({arr[r][c], arr[r][c + 1], arr[r][c + 2],
                               arr[r + 1][c + 1],
                               arr[r + 2][c], arr[r + 2][c + 1], arr[r + 2][c + 2]});
            }
        }
    }

    for (std::vector<int> row : hgs)
    {
        curr_hg_sum = 0;

        for (int element : row)
        {
            curr_hg_sum += element;
        }

        hg_sums.push_back(curr_hg_sum);
    }

    max = hg_sums[0];
    for (int i = 0; i < hg_sums.size(); i++)
    {

        if (hg_sums[i] > max)
        {
            max = hg_sums[i];
            max_idx = i;
        }
    }

    // Following two statements + loop will help you realize the bug
    // PrintTwoDVec(hgs);
    // std::cout << "\nMax Idx: " << max_idx << " | Max sum: " << max << "\n";
    // for (int element : hg_sums)
    // {
    //     std::cout << element << " ";
    // }
    // std::cout << "\n";

    std::cout << "The hour glass that has the max sum:\n";
    PrintHourGlassMax(max_idx, hgs);

    std::cout << "\nMax sum among all the hourglasses in the 2D array: ";
    std::cout << hg_sums[max_idx] << "\nMax index: " << max_idx << std::endl;

    return 0;
}