#include <iostream>
#include <string>
#include <utility>

template <typename T>
class Stek
{
	T* data;
	int amount;
	unsigned int curStored;
public:
	Stek(int _amount);
	~Stek();
	std::pair<bool, T> pop();
	bool push(T element);
	int size() { return curStored; };
};

template <typename T>
std::pair<bool, T> Stek<T>::pop()
{
	if (curStored == 0)
	{
		return std::pair<bool, T>(0, NULL);
	}
	curStored--;
	return std::pair<bool, T>(1, data[curStored + 1]);
}

template <typename T>
bool Stek<T>::push(T element)
{
	if (curStored < amount - 1)
	{
		curStored++;
		data[curStored] = element;
		return 1;
	}
	else
	{
		return 0;
	}
}

template <typename T>
Stek<T>::Stek(int _amount)
{
	curStored = 0;
	amount = _amount;
	data = new T[amount];
}

template <typename T>
Stek<T>::~Stek()
{
	delete[] data;
}

bool chkStr(std::string str)
{
	Stek<char>* stek = new Stek<char>(100);
	for (int i = 0; i < str.size(); i++)
	{
		if (str[i] == '(')
		{
			bool isPushed = stek->push(str[i]);
			if (!isPushed)
			{
				std::cout << "Could not push to stek. Stek overflowed\n";
				return -1;
			}
		}
		else if (str[i] == ')')
		{
			std::pair<bool, char> popRes = stek->pop();
			if (popRes.first == 0)
			{
				return 0;
			}
		}
	}
	if(stek->size() == 0)
		return 1;
	return 0;
}

int main()
{
	int action = 1;
	while (action != 0)
	{
		std::cout << "Enter action. 1 - check if string is correct, 0 - quit: ";
		std::cin >> action;
		if (action == 0)
			break;
		else if (action == 1)
		{
			std::string str;
			std::cout << "Enter string to check: ";
			std::cin >> str;
			bool isCorrect = chkStr(str);
			if (isCorrect)
			{
				std::cout << "String is correct\n";
			}
			else
			{
				std::cout << "String can't be a correct mathematical expression\n";
			}
		}
	}
	return 0;
}