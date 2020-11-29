#include <iostream>
#include <vector>

int occurence(std::vector<int> array, int value, bool isFirst)
{
	int first = 0;
	int last = array.size() - 1;
	int result = -1;

	while (first <= last)
	{
		int mid = first + ((last - first) / 2);
		if (array[mid] == value)
		{
			result = mid;
			if (isFirst == true)
			{
				last = last - 1;
			}
			else
			{
				first = first + 1;
			}
		}
		else if (value < array[mid])
		{
			last = mid - 1;
		}
		else
		{
			first = mid + 1;
		}
	}
	return result;
}

int count(std::vector<int> array, int value)
{
	int first = occurence(array, value, true);
	if (first == -1)
	{
		return 0;
	}
	else
	{
		int last = occurence(array, value, false);
		return (last - first + 1);
	}
}

int main()
{
	std::vector<int> array{1, 2, 3, 3, 4, 4, 4, 4, 5, 5, 5, 6, 7, 8, 8, 8, 9, 9, 10};
	std::cout << "The count of 8 is " << count(array, 4);
}
