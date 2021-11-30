#include <iostream>
#include <vector>

std::vector<std::string> solutionSet;

void permutate(std::string inputString, int leftIndex, int rightIndex)
{

    for (int currentIndex = leftIndex; currentIndex <= rightIndex; currentIndex++)
    {
        if (leftIndex == rightIndex)
        {
            return;
        }

        // swap every element to be first element and find all possible permutations
        std::swap(inputString[currentIndex], inputString[leftIndex]);

        // recursively permutate until left index is equal to the right one
        permutate(inputString, leftIndex + 1, rightIndex);

        // add the unique solution to the solution set
        solutionSet.push_back(inputString);

        // backtrack to original string after permutating
        std::swap(inputString[currentIndex], inputString[leftIndex]);
    }
}

int main()
{
    std::string inputString;
    std::cout << "enter input string: ";
    std::cin >> inputString;
    permutate(inputString, 0, inputString.length() - 1);

    for (std::string element : solutionSet)
    {
        std::cout << element << "\n";
    }
}
