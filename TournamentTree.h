#pragma once
#include <list>
#include "windows.h"

std::list<TournamentNode*> myCreateTreeTermLeaves(int* data, int dataAm)
{
	std::list<TournamentNode*> nodeList;
	for (int i = 0; i < dataAm; i++)
	{
		nodeList.push_back(new TournamentNode(data[i], 0, NULL, NULL));
	}
	return nodeList;
}

template<typename T>
T getMax(T a, T b)
{
	return (a > b) ? a : b;
}

int getMaxFromArray(std::list<TournamentNode*>& nodeList)
{
	int size = nodeList.size();
	for (auto it = nodeList.begin(); it != nodeList.end(); it++)
	{
		auto it2 = it;
		it2++;
		if (it2 != nodeList.end() && (*it2)->getLevel() == (*it)->getLevel())
		{
			nodeList.push_back(new TournamentNode(getMax((*it)->getValue(), (*it2)->getValue()), (*it)->getLevel() + 1, *it, *it2));
			it = it2;
		}
		else if (it2 == nodeList.end())
		{
			int curMaxNum = (*it)->getValue();
			for (auto it3 = nodeList.begin(); (*it3)->getLevel() == 0; it3++)
			{
				if (**it3 == **it)
				{
					delete* it3;
					nodeList.erase(it3);
					break;
				}
			}
			int curSize = nodeList.size();
			for (int i = size - 1; i < curSize; i++)
			{
				nodeList.pop_back();
			}
			return curMaxNum;
		}
		else
		{
			nodeList.push_back(new TournamentNode((*it)->getValue(), (*it)->getLevel() + 1, *it, NULL));
		}
	}
}

int* sortDataTournament(int* data, int dataAm)
{
	int* sortedData = new int[dataAm];
	if (dataAm < 2)
	{
		for (int i = 0; i < dataAm; i++)
		{
			sortedData[i] = data[i];
		}
		return sortedData;
	}
	std::list<TournamentNode*> nodeList = myCreateTreeTermLeaves(data, dataAm);
	for (int i = 0; i < dataAm; i++)
	{
		int curMaxNum = getMaxFromArray(nodeList);
		sortedData[dataAm - i - 1] = curMaxNum;
	}
	return sortedData;
}