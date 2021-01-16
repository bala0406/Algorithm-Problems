#include <iostream>
#include <vector>
#include <algorithm>

long maxCrossingSum(std::vector<long> inputArray, long left, long mid, long right)
{
    //left to mid sum
    long leftSum = LONG_MIN;
    long currentSum = 0;
    for (long i = mid; i >= left; i--)
    {
        currentSum += inputArray[i];
        leftSum = std::max(leftSum, currentSum);
    }

    //mid to right sum
    long rightSum = LONG_MIN;
    currentSum = 0;
    for (long i = mid + 1; i <= right; i++)
    {
        currentSum += inputArray[i];
        rightSum = std::max(rightSum, currentSum);
    }

    return std::max(leftSum + rightSum, std::max(leftSum, rightSum));
}

long maxSubArraySum(std::vector<long> inputArray, int left, int right)
{
    if (left == right)
    {
        return inputArray[left];
    }
    
    long mid = (left + right) / 2;

    long leftSideSum = maxSubArraySum(inputArray, left, mid);
    long rightSideSum = maxSubArraySum(inputArray, mid + 1, right);
    long crossingSum = maxCrossingSum(inputArray, left, mid, right);

    return std::max(crossingSum, std::max(leftSideSum, rightSideSum));
}

int main()
{
    std::vector<long> inputArray{3,3,9,9,5};
    long modValue = 10;
    std::cout << maxSubArraySum(inputArray, 0, inputArray.size() - 1,modValue);
}
