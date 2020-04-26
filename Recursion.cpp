#include <stack>
#include <iostream>

double recurseEval(int n)
{
	if (n == 0)
		return 1;
	else
	{
		return (double)2 / n * recurseEval(n - 1);
	}
}

int main()
{
	int amount;
	std::cout << "Insert amount of elements in stack: ";
	std::cin >> amount;
	std::stack<double> stek;

	for (int i = 0; i < amount; i++)
	{
		stek.push(recurseEval(i));
	}
	for (int i = 0; i < amount; i++)
	{
		std::cout << stek.top() << "\n";
		stek.pop();
	}
	return 0;
}