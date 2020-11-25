#include <iostream>
#include <vector>
#include <algorithm>

//merging left and right array into a single array
std::vector<int> merge(std::vector<int> leftArray, std::vector<int> rightArray, std::vector<int> array)
{
	int currentIndexOfLeftArray = 0;
	int currentIndexOfRightArray = 0;
	int currentIndexOfArray = 0;

	//insert the smallest of current Index of leftArray and rightArray into array
	while (currentIndexOfLeftArray < leftArray.size() && currentIndexOfRightArray < rightArray.size())
	{
		if (leftArray[currentIndexOfLeftArray] < rightArray[currentIndexOfRightArray])
		{
			array[currentIndexOfArray] = leftArray[currentIndexOfLeftArray];
			currentIndexOfLeftArray++;
		}
		else
		{
			array[currentIndexOfArray] = rightArray[currentIndexOfRightArray];
			currentIndexOfRightArray++;
		}
		currentIndexOfArray++;
	}

	//to insert the remaining elements in leftArray which are left overs
	while (currentIndexOfLeftArray < leftArray.size())
	{
		array[currentIndexOfArray] = leftArray[currentIndexOfLeftArray];
		currentIndexOfLeftArray++;
		currentIndexOfArray++;
	}

	//to insert the remaining elements in rightArray which are left overs
	while (currentIndexOfRightArray < rightArray.size())
	{
		array[currentIndexOfArray] = rightArray[currentIndexOfRightArray];
		currentIndexOfRightArray++;
		currentIndexOfArray++;
	}
	return array;
}

void mergeSort(std::vector<int> &array)
{
	int size = array.size();
	int mid = size / 2;
	std::vector<int> leftArray(mid);
	std::vector<int> rightArray(size - mid);

	//if the array only has one element
	if (size < 2)
	{
		return;
	}

	//filling left array
	for (int i = 0; i < mid; i++)
	{
		leftArray[i] = array[i];
	}

	//filling right array
	for (int i = mid; i < size; i++)
	{
		rightArray[i - mid] = array[i];
	}

	mergeSort(leftArray);						 //recursively dividing left array
	mergeSort(rightArray);						 //recursively dividing right array
	array = merge(leftArray, rightArray, array); // sorting and merging left and right array back to the original array
}

int main()
{
	std::vector<int> array{23, 27, 2, 11, 15, 5, 9, 22, 14};
	mergeSort(array);

	for (int &element : array)
	{
		std::cout << element << "\t";
	}
}
