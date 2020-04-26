#include "InsertionSort.h"

void ROR(int* array, int begin, int end)
{
	if (begin >= end)
		return;
	int tmp = array[end];
	for (int i = end; i > begin; i--)
	{
		array[i] = array[i - 1];
	}
	array[begin] = tmp;
}

int insertionSort(int* array, int arrayAm)
{
	std::chrono::time_point<std::chrono::system_clock> start, end;
	start = std::chrono::system_clock::now();
	for (int i = 0; i < arrayAm; i++)
	{
		for (int j = 0; j < i; j++)
		{
			if (array[i] <= array[j])
			{
				ROR(array, j, i);
				break;
			}
		}
	}
	end = std::chrono::system_clock::now();
	return std::chrono::duration_cast<std::chrono::milliseconds>(end - start).count();
}