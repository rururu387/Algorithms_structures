#include <vector>
#include <chrono>
#include <stdlib.h>
#include <string>
#include <iostream>
#include "TournamentNode.h"
#include "TournamentTree.h"
#include <clocale>

void generateNumbers(int** data, int am, int lowerBorder, int upperBorder)
{
	delete[] *data;
	*data = new int[am];
	for (int i = 0; i < am; i++)
	{
		int a = rand() % ((upperBorder * lowerBorder > 0) ? (upperBorder - lowerBorder) + lowerBorder : (upperBorder + 1 - lowerBorder) + lowerBorder);
		(*data)[i] = a;
	}
}

int main()
{
	setlocale(LC_ALL, "Russian");
	srand(time(NULL));
	char action = '0';
	int lowerBorder = -1, upperBorder = -1;
	int* curData = new int[3];
	int dataAmount = -1;
	while (action != 'K')
	{
		std::cout << "Insert action. K - quit, ? - help, U - generate elements (set borders), G - generate elements (no borders), P - print data, W - print sorting time: ";
		std::cin >> action;
		if (action == '?')
		{
			std::cout << "UЦ задание условий дл€ генерации неупор€доченного массива (задаютс€ число       элементов и границы элементов неупор€доченного массива). «аданные услови€    сохран€ютс€ до следующего вызова функции УUФ;"
				"G Ц генераци€ неупор€доченного массива, необходима перед каждой сортировкой;"
			"P Ц вывод массива в текущем состо€нии : неупор€доченный(до сортировки) или упор€доченный(после неЄ);"
			"W - вывод времени сортировки;";
		}
		else if (action == 'G')
		{
			dataAmount = 2000;
			generateNumbers(&curData, dataAmount, -2000, 2000);
		}
		else if (action == 'U')
		{
			if (dataAmount <= 0)
			{
				std::cout << "Enter length of data: ";
				std::cin >> dataAmount;
				std::cout << "Enter the lowest number may be generated: ";
				std::cin >> lowerBorder;
				std::cout << "Enter the heighets number can be generated: ";
				std::cin >> upperBorder;
			}
			generateNumbers(&curData, dataAmount, lowerBorder, upperBorder);
		}
		else if (action == 'P')
		{
			for (int i = 0; i < dataAmount; i++)
			{
				std::cout << std::to_string(curData[i]) << '\t';
			}
			std::cout << '\n';
		}
		else if (action == 'W')
		{
			std::chrono::time_point<std::chrono::system_clock> start, end;
			start = std::chrono::system_clock::now();
			int* sortedData = sortDataTournament(curData, dataAmount);
			end = std::chrono::system_clock::now();
			int elapsedMilliseconds = std::chrono::duration_cast<std::chrono::milliseconds>(end - start).count();
			std::cout << "sorting complete. You can see printed data now. Sorting took: " << elapsedMilliseconds << "milliseconds\n";
			for (int i = 0; i < dataAmount; i++)
			{
				std::cout << std::to_string(sortedData[i]) << '\t';
			}
			std::cout << '\n';
		}
	}
	delete[] curData;
	return 0;
}