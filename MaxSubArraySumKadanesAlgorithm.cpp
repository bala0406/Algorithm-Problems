#include <iostream>
#include <vector>
#include <algorithm>

There is also a solution for O(n^3) which is kinda naive

brute force approach - O(n^2)
long maximumSubArray(std::vector<long> inputArray, long modValue)
{
    long maxValue = LONG_MIN;

    for (long i = 0; i < inputArray.size(); i++)
    {
        long sum = 0;
        for (long j = i; j < inputArray.size(); j++)
        {
            sum += inputArray[j];
            if (sum % modValue > maxValue)
            {
                maxValue = sum % modValue;
            }
        }
    }
    return maxValue;
}

//efficient method - Kadane's algorithm - Linear time
long maximumSubArray(std::vector<long> inputArray, long modValue)
{
    long maxValue = inputArray[0];
    long currentMax = inputArray[0];
    // we compare the current element with the sum of current element plus the previous element
    // so ultimately we are finding the best possible value for the current index
    // Thus we don't need to look elements beyond the last element to find the max sum
    for (int i = 0; i < inputArray.size(); i++)
    {
        currentMax = std::max(inputArray[i], currentMax + inputArray[i]);
        maxValue = std::max(maxValue, currentMax);
    }
    return maxValue;
}

int main()
{
    std::vector<long> inputArray{3, 3, 9, 9, 5};
    long modValue = 7;
    std::cout << maximumSubArray(inputArray, modValue);
}
