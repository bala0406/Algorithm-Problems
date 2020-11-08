#include<iostream>
#include<vector>
#include<stack>

//refer hackerrank for input format
//https://www.hackerrank.com/challenges/game-of-two-stacks/problem
int twoStacks(int x, std::vector<int> a, std::vector<int> b)
{
    std::stack<int> s1;
    std::stack<int> s2;
    int sum = x;

    for (int i = a.size() - 1; i >= 0; i--)
    {
        s1.push(a[i]);
    }

    for (int i = b.size() - 1; i >= 0; i--)
    {
        s2.push(b[i]);
    }

    std::vector<int> elements;
    int total = 0;

    for (int i = 0; i < a.size(); i++)
    {
        if (total + s1.top() <= sum)
        {

            elements.push_back(s1.top());
            total += s1.top();
            s1.pop();
        }
        else
        {
            break;
        }
    }
    int maxCount = elements.size();
    int currentCount = maxCount;

    int size = b.size();
    while (size)
    {
        if (total + s2.top() <= sum)
        {
            total += s2.top();
            s2.pop();
            size--;
            currentCount++;
            if (currentCount > maxCount)
            {
                maxCount = currentCount;
            }
            continue;
        }
        if (!elements.size())
        {
            break;
        }

        int value = elements.back();
        elements.pop_back();
        total -= value;
        currentCount--;
    }

    return maxCount;
}
