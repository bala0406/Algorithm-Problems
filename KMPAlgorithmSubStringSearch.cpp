#include <iostream>
#include <string>
#include <vector>

// brute force - O(n*m)
void subString(std::string string, std::string subStr)
{
    for (int i = 0; i <= string.size() - subStr.size(); i++)
    {
        int j = 0;
        for (j = 0; j < subStr.size(); j++)
        {
            if (subStr[j] != string[i + j])
            {
                std::cout << string[i + j] << "\t";
                break;
            }
        }
        if (j == subStr.size())
        {
            std::cout << "pattern match found at index " << i << "\n";
        }
    }
}

void buildLPSArray(std::string subStr, std::vector<int> &LPSTable)
{
    // since 0th index doesnt have any prefix or suffix the index starts from 1
    int currentIndex = 1;
    int lengthIndex = 0;

    while (currentIndex < subStr.length())
    {
        if (subStr[currentIndex] == subStr[lengthIndex])
        {
            LPSTable[currentIndex] = ++lengthIndex;
            currentIndex++;
        }
        else
        {
            if (lengthIndex != 0)
            {
                lengthIndex = LPSTable[lengthIndex - 1];
            }
            else
            {
                currentIndex++;
            }
        }
    }
}

// KMP algorithm
std::vector<int> subString(std::string string, std::string subStr)
{
    //build LPS(longest proper prefix) table
    std::vector<int> LPSTable(subStr.size(), 0);
    std::vector<int> subStringStartingIndices;
    buildLPSArray(subStr, LPSTable);

    // search
    int stringIndex = 0;
    int subStrIndex = 0;
    while (stringIndex < string.length())
    {
        if (string[stringIndex] == subStr[subStrIndex])
        {
            stringIndex++;
            subStrIndex++;
        }
        else
        {
            if (subStrIndex != 0)
            {
                subStrIndex = LPSTable[subStrIndex - 1];
            }
            else
            {
                stringIndex++;
            }
        }

        if (subStrIndex == subStr.length())
        {
            subStringStartingIndices.push_back(stringIndex - subStrIndex);
        }
    }
    return subStringStartingIndices;
}

int main()
{
    std::string string = "abacdabaababac";
    std::string subStr = "abac";

    std::cout << "the pattern is found at index(ices): ";
    for (int index : subString(string, subStr))
    {
        std::cout << index << "\t";
    }
}
