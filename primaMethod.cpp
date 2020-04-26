#include <iostream>
#include <cstring>
#include <climits>
const int vAmount = 8;

int edges[vAmount][vAmount] = {
  {0, 2, 0, 4, 0, 0, 6, 0},
  {2, 0, 1, 1, 2, 0, 0, 8},
  {0, 1, 0, 0, 7, 0, 0, 0},
  {4, 1, 0, 0, 0, 5, 1, 0},
  {0, 2, 7, 0, 0, 0, 2, 2},
  {0, 0, 0, 5, 0, 0, 1, 0},
  {6, 0, 0, 1, 2, 1, 0, 2},
  {0, 8, 0, 0, 2, 0, 2, 0},
};

int main()
{
    setlocale(LC_ALL, "Russian");
    unsigned int edgeAm = 0;
    bool isPicked[vAmount] = {0};

    isPicked[0] = 1;

    std::cout << "В остовной подграф входият:\n";
    while (edgeAm < vAmount - 1)
    {
        int min = INT_MAX;
        int v1 = 0;
        int v2 = 0;

        for (int i = 0; i < vAmount; i++)
        {
            if (isPicked[i])
            {
                for (int j = 0; j < vAmount; j++)
                {
                    if (!isPicked[j] && edges[i][j])
                    {
                        if (min > edges[i][j])
                        {
                            min = edges[i][j];
                            v1 = i;
                            v2 = j;
                        }
                    }
                }
            }
        }
        std::cout << "Ребро между вершинами " << v1 << " и " << v2 << ", имеет вес " << edges[v1][v2] << '\n';
        isPicked[v2] = true;
        edgeAm++;
    }

    return 0;
}