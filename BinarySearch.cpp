#include "BinarySearch.h"

std::pair<int, int> binarySearch(int* data, int dataAm, const int key)
{
	std::chrono::time_point<std::chrono::system_clock> start, end;
	start = std::chrono::system_clock::now();
	int i = 0, j = dataAm;
	int middle = (i + j) / 2;
	while (true)
	{
		middle = (i + j) / 2;

		if (data[middle] == key)
			break;

		if (data[middle] > key)
		{
			j = middle - 1;
		}
		else
		{
			i = middle + 1;
		}

		if (i > j)
		{
			end = std::chrono::system_clock::now();
			int elapsedMilliseconds = std::chrono::duration_cast<std::chrono::milliseconds>(end - start).count();
			return std::pair<int, int>(elapsedMilliseconds, -1);
		}
	}
	end = std::chrono::system_clock::now();
	int elapsedMilliseconds = std::chrono::duration_cast<std::chrono::milliseconds>(end - start).count();
	return std::pair<int, int>(elapsedMilliseconds, middle);
}