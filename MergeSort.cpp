#include "MergeSort.h"

void mergeSort(int* array, int end, int start)
{
	if (end > start)
	{
		int middle = (end + start) / 2;

		mergeSort(array, middle, start);
		mergeSort(array, end, middle + 1);
		merge(array, start, middle, middle + 1, end);
	}
}


void merge(int* array, int start1, int end1, int start2, int end2)
{
	int* part1 = new int[end1 - start1 + 1];
	int* part2 = new int[end2 - start2 + 1];
	for (int i = 0; i < end1 - start1 + 1; i++)
	{
		part1[i] = array[start1 + i];
	}
	for (int i = 0; i < end2 - start2 + 1; i++)
	{
		part2[i] = array[start2 + i];
	}

	int i = 0, j = 0;
	while (i != end1 - start1 + 1 || j != end2 - start2 + 1)
	{
		if (i == end1 - start1 + 1)
		{
			array[start1 + i + j] = part2[j];
			j++;
		}
		else if (j == end2 - start2 + 1)
		{
			array[start1 + i + j] = part1[i];
			i++;
		}
		else
		{
			if (part1[i] <= part2[j])
			{
				array[start1 + i + j] = part1[i];
				i++;
			}
			else
			{
				array[start1 + i + j] = part2[j];
				j++;
			}
		}
	}
}