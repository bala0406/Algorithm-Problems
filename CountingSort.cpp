#include <iostream>
#include <vector>

std::vector<int> countingSort(std::vector<int> inputArray)
{
    int maxElement = 0;
    // find the maximum element in the input array
    for (int i = 0; i < inputArray.size(); i++)
    {
        if (inputArray[i] > maxElement)
        {
            maxElement = inputArray[i];
        }
    }

    // initialize countArray of size maxElement
    std::vector<int> countArray(maxElement + 1, 0);

    //populate the count array with number of occurences
    for (int i = 0; i < inputArray.size(); i++)
    {
        countArray[inputArray[i]]++;
    }

    //calculate the running sum
    for (int i = 1; i < countArray.size(); i++)
    {
        countArray[i] += countArray[i - 1];
    }

    std::vector<int> outputArray(inputArray.size());

    // placement of elements in outputArray by traversing the input array in reverse
    for (int i = inputArray.size() - 1; i >= 0; i--)
    {
        outputArray[countArray[inputArray[i]] - 1] = inputArray[i];
        countArray[inputArray[i]]--;
    }
    return outputArray;
}

int main()
{
    std::vector<int> inputArray{4, 3, 1, 3, 5, 4, 6, 3, 3, 5, 2, 0};
    for (int element : countingSort(inputArray))
    {
        std::cout << element << "\t";
    }
}
