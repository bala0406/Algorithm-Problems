#include <iostream>

template <typename T>

//swaps two elements
void swap(T &element1, T &element2)
{
	T temp = element1;
	element1 = element2;
	element2 = temp;
}

//divides the array into left and right partitions and performs swap when the elements are smaller than pivot
int partition(int *array, int start, int end)
{
	int index = start;
	int pivot = array[end];

	for (int i = start; i < end; i++)
	{
		if (array[i] <= pivot)
		{
			swap<int>(array[index], array[i]); //swaps the index and current element
			index++;
		}
	}
	swap<int>(array[end], array[index]); //swaps the index and last element, so that the pivot is in the appropriate position
	return index;
}

//quick sort recursive function
int *quickSort(int *array, int start, int end)
{
	if (start < end)
	{
		int partitionIndex = partition(array, start, end);
		quickSort(array, start, partitionIndex - 1);
		quickSort(array, partitionIndex + 1, end);
	}
	return array;
}

int main()
{
	int array[]{23, 27, 2, 11, 15, 5, 9, 22, 14};
	int size = sizeof(array) / sizeof(array[0]);
	int *result = quickSort(array, 0, size - 1);

	for (int i = 0; i < size; i++)
	{
		std::cout << array[i] << "\t";
	}
}
