#include "LinearCongruentialGenerator.h"

int linearCongruentialRND(int* array, const int rndAm)
{
	auto start = std::chrono::system_clock::now();
	std::time_t tt;
	tt = std::chrono::system_clock::to_time_t(start);
	int b = 127;
	int x0 = tt % 100;
	int k = 43;
	int m = 100;
	array[0] = x0;
	for (int i = 1; i < rndAm; i++)
	{
		array[i] = (array[i - 1] * b + k) % m;
	}
	auto end = std::chrono::system_clock::now();
	return std::chrono::duration_cast<std::chrono::milliseconds>(end - start).count();
}