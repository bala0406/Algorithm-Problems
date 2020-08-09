#include <iostream>
#include <vector>
#include <algorithm>

// O(n^2) - Iterative - not efficient
long largestRectangle(std::vector<int> heights) {

    int maxArea = 0;
    int minHeight = 0;

    for(int i = 0; i < heights.size(); i++)
    {
        minHeight = heights[i];
        for(int j = i; j <heights.size(); j++)
        {
            minHeight = std::min(minHeight,heights[j]);
            maxArea = std::max(maxArea,minHeight * ((j-i) + 1));
        }
    }
    return maxArea;
}

int main()
{
    std::vector<int> heights{1,2,3,4,5};
    std::cout << largestRectangle(heights); 
}
