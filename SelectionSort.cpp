#include "SelectionSort.h"

int selectionSort(int* array, int arrayAm)
{
	std::chrono::time_point<std::chrono::system_clock> start, end;
	start = std::chrono::system_clock::now();
	for (int i = 0; i < arrayAm; i++)
	{
		int min = array[i];
		int minIndex = i;
		for (int j = i + 1; j <= arrayAm; j++)
		{
			if (array[j] < min)
			{
				min = array[j];
				minIndex = j;
			}
		}
		int tmp = array[i];
		array[i] = min;
		array[minIndex] = tmp;
	}
	end = std::chrono::system_clock::now();
	return std::chrono::duration_cast<std::chrono::milliseconds>(end - start).count();
}