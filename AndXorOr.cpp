#include<iostream>
#include<vector>
#include<stack>
#include<algorithm>

//inefficient - o(n^2)
//--Typical brute force method
//--Calculate the minimum numbers and evaluate the expression for each iteration

//efficient - O(n)
int andXorOr(std::vector<int> numbers)
{
    std::stack<int> stack;
    int maxValue = 0;
    int result = 0;
    
    for(int i = 0; i < numbers.size(); i++)
    {
        while(!stack.empty())
        {
            result = stack.top() ^ numbers[i];
            maxValue = std::max(result,maxValue);
            if(numbers[i] < stack.top())
            {
                stack.pop();
            }
            else
            {
                break;
            }
        }
        stack.push(numbers[i]);
    }
    return maxValue;
}


int main()
{
	std::vector<int> a{9,6,3,5,2};
	std::cout << andXorOr(a);
}
