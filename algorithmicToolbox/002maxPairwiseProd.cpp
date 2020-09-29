#include <iostream>
#include <vector>
#include <algorithm>

long long MaximumPairwiseProduct(const std::vector<int>& numbers) 
{
    long long maxProduct = 0;
    int n = numbers.size();

    for (int first = 0; first < n; ++first) 
    {
        for (int second = first + 1; second < n; ++second) 
        {
            maxProduct = std::max(maxProduct, numbers[first] * numbers[second]);
        }
    }

    return maxProduct;
}

int main()c
{
    int n;
    std::cin >> n;
    std::vector<int> numbers(n);
    for (int i = 0; i < n; ++i)
    {
        std::cin >> numbers[i];
    }

    std::cout << MaximumPairwiseProduct(numbers) << "\n";
    return 0;
}