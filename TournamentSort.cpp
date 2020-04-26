#include <vector>
#include <chrono>
#include <stdlib.h>
#include <string>
#include <iostream>
#include "TournamentNode.h"
#include "TournamentTree.h"
#include "SelectionSort.h"
#include "MergeSort.h"
#include <clocale>
#include "InsertionSort.h"
#include "BinarySearch.h"
#include "InterpolationSearch.h"
#include "LinearCongruentialGenerator.h"

void generateNumbers(int** data, int am, int lowerBorder, int upperBorder)
{
	delete[] *data;
	*data = new int[am];
	for (int i = 0; i < am; i++)
	{
		int a = rand() % ((upperBorder * lowerBorder > 0) ? (upperBorder - lowerBorder) : (upperBorder + 1 - lowerBorder)) + lowerBorder;
		(*data)[i] = a;
	}
}

int main()
{
	setlocale(LC_ALL, "Russian");
	srand(time(NULL));
	std::string action = "0";
	int lowerBorder = -1, upperBorder = -1;
	int* curData = new int[3];
	int dataAmount = -1;
	bool isDataSorted = 0;
	while (action.compare("K"))
	{
		std::cout << ">>Insert action. K - quit, ? - help, U - generate elements (set borders), G - generate elements (no borders), T - tournament sort, M - merge sort, S - selction sort, I - insertion sort, BSearch - binary search, ISearch - interpolar search, RNDCongr - linear congruential generator, P - print data: ";
		std::cin >> action;
		if (action.compare("?") == 0)
		{
			std::cout << "¬ этой программе реализованы методы поиска и сортировки, которые было необходимо сделать в рамках лабораторной работы.\n"
						 "ѕосле каждого выхова функции сортировки или поиска выводитс€ врем€, потраченное на операцию.\n"
						 "ѕрограмма хранит единственный массив данных, с которым и производ€тс€ операции. Ќиже приведены способы вызова описание каждой из них:\n"
						 "K Ц штатный выход из программы;\n"
						 "U Ц задание условий дл€ генерации неупор€доченного массива (задаютс€ число элементов и границы элементов неупор€доченного массива);\n"
						 "G Ц генераци€ неупор€доченного массива, необходима перед каждой сортировкой. ƒлина задаетс€  вручную;\n"
						 "T Ц турнирна€ сортировка;\n"
						 "M Ц сортировка сли€нием;\n"
						 "S Ц сортировка вставкой (проста€);\n"
						 "BSearch Ц бинарный поиск по массиву. ѕеред вызовом функций поиска убедитесь, что массив отсортирован;\n"
						 "ISearch Ц интерпол€ционный поиск;\n"
						 "RNDCongr Ц линейный конгруэнтный генератор случайных чисел;\n"
						 "P Ц вывод массива в текущем состо€нии;\n"
						 "W Ц вывод времени сортировки;\n";
		}
		else if (action.compare("G") == 0)
		{
			std::cout << "Insert amount of numbers to sort: ";
			std::cin >> dataAmount;
			generateNumbers(&curData, dataAmount, 0, 32767);
			isDataSorted = 0;
		}
		else if (action.compare("U") == 0)
		{
			//if (dataAmount <= 0)
			//{
			std::cout << "Enter length of data: ";
			std::cin >> dataAmount;
			std::cout << "Enter the lowest number may be generated: ";
			std::cin >> lowerBorder;
			std::cout << "Enter the heighets number can be generated: ";
			std::cin >> upperBorder;
			//}
			//else
			//{
				//std::cout << "Params already set\n";
			//}
			generateNumbers(&curData, dataAmount, lowerBorder, upperBorder);
			isDataSorted = 0;
		}
		else if (action.compare("P") == 0)
		{
			for (int i = 0; i < dataAmount; i++)
			{
				std::cout << std::to_string(curData[i]) << '\t';
			}
			std::cout << '\n';
		}
		else if (action.compare("T") == 0)
		{
			std::pair<int*, int> sortedData = sortDataTournament(curData, dataAmount);
			std::cout << "Sorting complete. It took: " << sortedData.second << " milliseconds\n";
			isDataSorted = 1;
		}
		else if (action.compare("M") == 0)
		{
			std::chrono::time_point<std::chrono::system_clock> start, end;
			start = std::chrono::system_clock::now();
			mergeSort(curData, dataAmount - 1);
			end = std::chrono::system_clock::now();
			int elapsedMilliseconds = std::chrono::duration_cast<std::chrono::milliseconds>(end - start).count();
			std::cout << "Sorting complete. It took: " << elapsedMilliseconds << " milliseconds\n";
			isDataSorted = 1;
		}
		else if (action.compare("S") == 0)
		{
			int elapsedMilliseconds = selectionSort(curData, dataAmount - 1);
			std::cout << "Sorting complete. It took: " << elapsedMilliseconds << " milliseconds\n";
			isDataSorted = 1;
		}
		else if (action.compare("I") == 0)
		{
			int elapsedMilliseconds = insertionSort(curData, dataAmount);
			std::cout << "Sorting complete. It took: " << elapsedMilliseconds << " milliseconds\n";
			isDataSorted = 1;
		}
		if (action.compare("BSearch") == 0)
		{
			if (isDataSorted == 0)
			{
				std::cout << "Data is not sorted. Can't search quickly in unordered data\n";
				break;
			}
			int key = 0;
			std::cout << "Enter key to search: ";
			std::cin >> key;
			std::pair<int, int> resPair = binarySearch(curData, dataAmount, key);
			if(resPair.second >= 0)
				std::cout << "It took " << resPair.first << " milliseconds to find that key " << key << " is located in position " << resPair.second + 1 << " in current array\n";
			else
			{
				std::cout << "It took " << resPair.first << " milliseconds to find that key " << key << " does not exist in current array\n";
			}
		}
		if (action.compare("ISearch") == 0)
		{
			if (isDataSorted == 0)
			{
				std::cout << "Data is not sorted. Can't search quickly in unordered data\n";
				break;
			}
			int key = 0;
			std::cout << "Enter key to search: ";
			std::cin >> key;
			std::pair<int, int> resPair = interpolationSearch(curData, dataAmount, key);
			if (resPair.second >= 0)
				std::cout << "It took " << resPair.first << " milliseconds to find that key " << key << " is located in position " << resPair.second + 1 << " in current array\n";
			else
			{
				std::cout << "It took " << resPair.first << " milliseconds to find that key " << key << " does not exist in current array\n";
			}
		}
		if (action.compare("RNDCongr") == 0)
		{
			std::cout << "Enter amount of numbers to generate: ";
			std::cin >> dataAmount;
			delete[] curData;
			curData = new int[dataAmount];
			int elapsedTime = linearCongruentialRND(curData, dataAmount);
			std::cout << "It took " << elapsedTime << " milliseconds to generate " << dataAmount << " numbers\n";
		}
	}
	delete[] curData;
	return 0;
}