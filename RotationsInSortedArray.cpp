#include <iostream>
#include <vector>

int rotations(std::vector<int> array)
{
	//inorder to find the number of rotations we need to find the smallest element and its position,
	//so we can calculate its deviation from the starting point i.e., the index of the smallest element
	//is the number of rotations that the array has undergone

	//conditions for finding rotations
	// 1 - there should be no duplicates
	// 2- the array should be sorted and rotated
	int low = 0;
	int high = array.size() - 1;

	while (low <= high)
	{
		int mid = low + ((high - low) / 2);
		//case:1 - if array[low] <= array[high], then the array is sorted and hence there are no rotations
		if (array[low] <= array[high])
		{
			return low;
		}
		//case:2 - the lowest element in the array i.e., the pivot has a property by which it is
		//lesser than both the previous element and the next element in the circular array
		if (array[mid] < array[mid - 1] && array[mid] < array[mid + 1])
		{
			return mid;
		}
		//case:3 - if array[low] < array[mid], then the first half is completely sorted and there is no possibilty
		//that our smallest element lies in that interval and hence they can be discarded
		if (array[low] < array[mid])
		{
			low = mid + 1;
		}
		//case:4 - if array[mid] < array[high], then the second half is completely sorted and there is no possibilty
		//that our smallest element lies in that interval and hence they can be discarded
		else if (array[mid] < array[high])
		{
			high = mid - 1;
		}
	}
	return 0;
}

int main()
{
	std::vector<int> array{4, 5, 6, 7, 8, 9, 1, 2, 3};
	std::vector<int> array1{1, 2, 3, 4, 5, 6, 7};
	std::cout << "The no. of rotations in the sorted array is " << rotations(array) << "\n";
	std::cout << "The no. of rotations in the sorted array is " << rotations(array1) << "\n";
}
