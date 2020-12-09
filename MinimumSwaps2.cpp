#include <iostream>
#include <unordered_map>
#include <vector>

//efficient algorithm - since we need only the swap count we acutally dont need to swap the values in this case
//this method only works if the elements are consecutive
int minimumSwaps(std::vector<int> array)
{
    for (int &element : array)
    {
        element = element - 1;
    }
    std::vector<bool> isVisited(array.size());

    std::unordered_map<int, int> values;

    //insert the index and the value in the index into the hashmap
    for (int i = 0; i < array.size(); i++)
    {
        values.insert(std::pair<int, int>(i, array[i]));
    }
    // for (auto element : values)
    // {
    //     std::cout << element.first << element.second;
    // }
    int swapCount = 0;

    for (int i = 0; i < values.size(); i++)
    {
        int nextValue = 0;
        if (isVisited[i] == false)
        {
            isVisited[i] = true;
            //Look at each index and compare the index position with its element value
            //if its same then move to the next index position.
            if (i == values.at(i))
            {
                continue;
            }
            //If index position is not the same as element value
            //then treat element value as index value for finding the next element.
            else
            {
                int currentValue = values.at(i);
                //If we come back to the visited element then there exist a cycle,
                //then count the size of that cycle, the number of swaps for particular cycle would be size-1,
                //do this for all the cycles and add them together.
                while (true)
                {
                    if (isVisited[currentValue] == true)
                    {
                        break;
                    }
                    isVisited[currentValue] = true;
                    nextValue = values.at(currentValue);
                    currentValue = nextValue;
                    swapCount++;
                }
            }
        }
    }
    return swapCount;
}

int main()
{
    std::cout << minimumSwaps({7, 1, 3, 2, 4, 5, 6});
}
