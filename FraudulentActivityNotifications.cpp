#include <iostream>
#include <vector>

// returns 2 * median
int getMedianx2(std::vector<int> countArray, int trailingDays)
{
    for (int i = 1; i < countArray.size(); i++)
    {
        // we're calculating the running sum which at any index represents the number of elements present before the current index
        if (i != 0)
        {
            countArray[i] += countArray[i - 1];
        }

        // instead of division, multiplication is used to avoid floating point errors
        // we're multiplying by two because the question was to check the current amount with twice the median
        if (countArray[i] * 2 == trailingDays)
        {
            // if the trailing days is even, the average of the middle two numbers is the median
            // here because multiplication is used instead of division the same result can be achieved
            // by simply adding one i.e., rounding up the result
            return (i * 2) + 1;
        }
        if (countArray[i] * 2 > trailingDays)
        {
            // if the days is odd, then the median is the middle element
            // thus median can be returned by mutiplying the current index by 2.
            return i * 2;
        }
    }
    return 0;
}

int ActivityNotifications(std::vector<int> expenditures, int trailingDays)
{
    int notificationCount = 0;

    //frequency array
    std::vector<int> countArray(201, 0);

    //to calculate the count frequency for initial trailing days
    for (int i = 0; i < trailingDays; i++)
    {
        countArray[expenditures[i]]++;
    }

    for (int i = trailingDays; i < expenditures.size(); i++)
    {
        // calculate the median for current sliding window using frequency array and trailing days
        int medianx2 = getMedianx2(countArray, trailingDays);

        // given condition check
        if (expenditures[i] >= medianx2)
        {
            notificationCount++;
        }

        // to break the loop when last element of expenditures is reached to avoid
        // un necessary movement of sliding window
        if (i == expenditures.size() - 1)
        {
            break;
        }

        //moves the sliding window
        countArray[expenditures[i - trailingDays]]--;
        countArray[expenditures[i]]++;
    }

    return notificationCount;
}

int main()
{
    //example
    std::vector<int> expenditures{2, 3, 4, 2, 3, 6, 8, 4, 5};
    int trailingDays = 5;
    std::cout << ActivityNotifications(expenditures, trailingDays);
}
