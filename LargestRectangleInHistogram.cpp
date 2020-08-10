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


//O(n) - only one iteration - efficient
long largestRectangle(std::vector<int> heights)
{

    std::stack<int> stack;
    int maxArea = 0;
    int indexOfCurrentMax = 0;
    int currentArea = 0;

    int i = 0;
    while(i < heights.size())
    {
        if(stack.empty() || heights[stack.top()] <= heights[i])
        {
            stack.push(i);
            i++;
        }
        else
        {
            indexOfCurrentMax = stack.top();
            stack.pop();
            currentArea = heights[indexOfCurrentMax] * (stack.empty() ? (i) : ((i - 1 - stack.top())));
            if(currentArea > maxArea)
            {
                maxArea = currentArea;
            }
        }
    }
    while (stack.empty() == false)
       {
           indexOfCurrentMax = stack.top();
           stack.pop();
           currentArea = heights[indexOfCurrentMax] * (stack.empty() ? (i) : ((i - 1 - stack.top())));
           if(currentArea > maxArea)
           {
               maxArea = currentArea;
           }
       }  
   return maxArea;
}

int main()
{
    std::vector<int> heights{1,2,3,4,5};
    std::cout << largestRectangle(heights); 
}
