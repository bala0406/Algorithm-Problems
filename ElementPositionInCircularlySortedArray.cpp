#include <iostream>
#include <vector>

int circularlySortedArrayPosition(std::vector<int> array, int element)
{
	//to find an element in a cicularly sorted array
	int low = 0;
	int high = array.size() - 1;

	while (low <= high)
	{
		int mid = low + ((high - low) / 2);
		//case1 - if the element is equal to array[mid]
		if (element == array[mid])
		{
			return mid;
		}
		//case2 - if array[low] <= array[mid] then this range is completely sorted
		//case2A - if element > array[low] and element < array[mid]
		//case2B - else discard
		if (array[low] < array[mid])
		{
			if (element > array[low] && element < array[mid])
			{
				high = mid - 1;
			}
			else
			{
				low = mid + 1;
			}
		}
		//case3 - if array[mid] <= array[high] then this range is sorted
		//case3A - if element > array[mid] and element < array[high]
		//case3B - else discard
		else
		{
			if (element > array[mid] && element < array[high])
			{
				low = mid + 1;
			}
			else
			{
				high = mid - 1;
			}
		}
	}
	return -1;
}

int main()
{
	std::vector<int> array{3, 4, 5, 6, 7, 1, 2};
	std::cout << circularlySortedArrayPosition(array, 4);
}
