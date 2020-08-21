#include <iostream>
#include <vector>
#include <stack>
#include <algorithm>

//iterative - o(n^2) - not efficient
void stockSpan(std::vector<int> stockPrice)
{
    std::vector<int> stocks(stockPrice.size());

    stocks[0] = 1;
    for (int i = 1; i < stockPrice.size(); i++)
    {
        stocks[i] = 1;
        for (int j = i - 1; j >= 0 ; --j)
        {
            if (stockPrice[i] >= stockPrice[j])
            {
                stocks[i]++;
            }
        }
    }
    std::cout << "\n" << "---------" << "\n";
    for (int i = 0; i < stocks.size(); i++)
    {
        std::cout << stocks[i] << "\n";
    }
}

//iterative - o(n) - efficient
void stockSpan(std::vector<int> stockPrice)
{
    std::stack<int> stack;
    stack.push(0);
    int top;
    int maxSpan = 1;
    std::vector<int> spans;
    spans.push_back(1);

    for (int i = 1; i < stockPrice.size(); i++)
    {
        int currentSpan = 1;
        while (!stack.empty() && stockPrice[i] > stockPrice[stack.top()])
        {
            stack.pop();
        }
        currentSpan = i - (!stack.empty() ? stack.top() : -1);
        stack.push(i);
        spans.push_back(currentSpan);
        maxSpan = std::max(maxSpan, currentSpan);
    }

    //printing max value
    std::cout << "\nmax:"
              << maxSpan
              << "\n";

    std::cout << "---------------"
              << "\n"
              << "span values:\n";
    //printing all span values
    for (int i = 0; i < spans.size(); i++)
    {
        std::cout << spans[i] << "\n";
    }
}


int main()
{
    // int count;
    // std::cin >> count;
    std::vector<int> stockPrice { 10, 4, 5, 90, 120, 80 };
    // for (int i = 0; i < count; i++)
    // {
    //     std::cin >> stockPrice[i];
    // }
    stockSpan(stockPrice);
    return 0;
}
