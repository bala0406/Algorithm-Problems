#include <iostream>
#include <vector>

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
