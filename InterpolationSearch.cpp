#include "InterpolationSearch.h"
#include <iostream>

std::pair<int, int> interpolationSearch(int* data, int dataAm, const int key)
{
	std::chrono::time_point<std::chrono::system_clock> start, end;
	start = std::chrono::system_clock::now();
	int i = 0, j = dataAm - 1;
	int d = 1;
	while (d != 0)
	{
		d = (j - i) * (key - data[i]) / (data[j] - data[i]);
		i += d;
		if (data[d] > key)
		{
			end = std::chrono::system_clock::now();
			int elapsedMilliseconds = std::chrono::duration_cast<std::chrono::milliseconds>(end - start).count();
			return std::pair<int, int>(elapsedMilliseconds, -1);
		}
	}
	end = std::chrono::system_clock::now();
	int elapsedMilliseconds = std::chrono::duration_cast<std::chrono::milliseconds>(end - start).count();
	return std::pair<int, int>(elapsedMilliseconds, i);
}