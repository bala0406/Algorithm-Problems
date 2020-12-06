#include <iostream>
#include <vector>

//This is a hacker rank problem called sockMerchant

//if present returns index of the element else returns -1
int findIndex(const std::vector<int> &pairs, int element)
{
    if (pairs.empty())
        return -1;
    for (int i = 0; i < pairs.size(); i++)
    {
        if (pairs[i] == element)
        {
            return i;
        }
    }
    return -1;
}

int sockMerchant(std::vector<int> &array)
{
    std::vector<int> pairs;
    int pairCount = 0;

    for (int i = 0; i < array.size(); i++)
    {
        int index = findIndex(pairs, array[i]);

        if (index == -1) //if there are no colors in pairs or the current color is not present in pairs
        {
            pairs.push_back(array[i]);
        }
        else
        {
            pairCount++;
            pairs.erase(pairs.begin() + index); //as the color pair is found, total count can be incremented and their entry can be removed
        }
    }
    return pairCount;
}

int main()
{
    std::vector<int> array{10, 20, 20, 10, 10, 30, 50, 10, 20}; // color pairs input
    std::cout << "number of pairs: " << sockMerchant(array);
}
