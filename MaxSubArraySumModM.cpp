#include <iostream>
#include <set>
#include <vector>
#include <algorithm>

long maximumSubArraySum(std::vector<long> inputArray, long modValue)
{
    long currentPrefixSum = 0;
    long maxValue = 0;
    
    //using set as red black tree (self-balancing) has log n time for performing operations
    std::set<long> set;
    set.insert(0);

    for (int i = 0; i < inputArray.size(); i++)
    {
        //calculating the current prefix sum
        currentPrefixSum = (currentPrefixSum + inputArray[i]) % modValue;

        //finding the maximum of prefix sum
        maxValue = std::max(maxValue, currentPrefixSum);

        //smallest element greater that prefixSum
        std::set<long>::iterator leastGreaterElement = set.lower_bound(currentPrefixSum + 1);

        //finding the maximum if current prefix is not the maximum
        if (leastGreaterElement != set.end())
        {
            maxValue = std::max(maxValue, (currentPrefixSum - (*leastGreaterElement) + modValue) % modValue);
        }

        set.insert(currentPrefixSum);
    }

    return maxValue;
}

int main()
{
    std::vector<long> inputArray{3, 3, 9, 9, 5};
    long modValue = 7;
    std::cout << maximumSubArraySum(inputArray, modValue);
}
