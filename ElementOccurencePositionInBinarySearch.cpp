#include <iostream>
#include <vector>

int firstOccurence(std::vector<int> array, int element)
{
	int first = 0;
	int last = array.size() - 1;
	int result = -1;

	while (first <= last)
	{
		int mid = first + ((last - first) / 2);

		if (element == array[mid])
		{
			result = mid;
			last = last - 1;
		}
		else if (element < array[mid])
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

int lastOccurence(std::vector<int> array, int element)
{
	int first = 0;
	int last = array.size() - 1;
	int result = -1;

	while (first <= last)
	{
		int mid = first + ((last - first) / 2);

		if (element == array[mid])
		{
			result = mid;
			first = first + 1;
		}
		else if (element < array[mid])
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

int binarySearch(std::vector<int> array, int element)
{
	int first = 0;
	int last = array.size() - 1;

	while (first <= last)
	{
		int mid = first + ((last - first) / 2);

		if (element == array[mid])
		{
			return mid;
		}
		else if (element < array[mid])
		{
			last = mid - 1;
		}
		else
		{
			first = mid + 1;
		}
	}
	return -1;
}

int binarySearchRecursive(std::vector<int> array, int first, int last, int element)
{

	if (first > last)
	{
		return -1;
	}

	int mid = first + ((last - first) / 2);

	if (array[mid] == element)
	{
		return mid;
	}
	else if (element < array[mid])
	{
		return binarySearchRecursive(array, first, mid - 1, element);
	}
	else
	{
		return binarySearchRecursive(array, mid + 1, last, element);
	}
	return -1;
}

int main()
{
	std::vector<int> array{1, 2, 3, 4, 5, 6, 7, 8};
	std::cout << "The element is found at:" << binarySearch(array, 7) << "\n";
	std::cout << "The element is found at:" << binarySearchRecursive(array, array[0], array.size() - 1, 7) << "\n";

	std::vector<int> array1{1, 1, 2, 2, 2, 3, 3, 3, 4, 4, 4, 4, 4, 5, 6, 7, 7, 8, 9, 9, 9, 10};
	std::cout << "The first occurence of the element is at:" << firstOccurence(array1, 9) << "\n";
	std::cout << "The last occurence of the elment is at:" << lastOccurence(array1, 9) << "\n";
}
