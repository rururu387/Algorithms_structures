#include <iostream>
#include <algorithm>
#include <vector>

class Graph
{
    std::vector<std::pair<int, std::pair<int, int>>> edges;
    std::vector<std::pair<int, std::pair<int, int>>> ostov;
    int* parent;
    int vAmount;

public:
    Graph(int vAmount);
    void addEdge(int v1, int v2, int weight);
    int findSet(int i);
    void uniteSet(int u, int v);
    void kruskalMethod();
    void print();

};

Graph::Graph(int _vAmount)
{
    vAmount = _vAmount;
    parent = new int[vAmount];
    for (int i = 0; i < vAmount; i++)
        parent[i] = i;

    edges.clear();
    ostov.clear();
}

void Graph::kruskalMethod()
{
    int i, uRep, vRep;
    sort(edges.begin(), edges.end());
    for (i = 0; i < edges.size(); i++)
    {
        uRep = findSet(edges[i].second.first);
        vRep = findSet(edges[i].second.second);
        if (uRep != vRep)
        {
            ostov.push_back(edges[i]);
            uniteSet(uRep, vRep);
        }
    }
}

void Graph::addEdge(int v1, int v2, int weight)
{
    edges.push_back(std::pair<int, std::pair<int, int>>(weight, std::pair<int, int>(v1, v2)));
}

void Graph::print()
{
    std::cout << "Ребра остовного подграфа\n";
    for (int i = 0; i < ostov.size(); i++)
    {
        std::cout << "Между " << ostov[i].second.first << " и " << ostov[i].second.second << " вершинами, вес " << ostov[i].first << '\n';
    }
}

int Graph::findSet(int i)
{
    if (i == parent[i])
    {
        return i;
    }
    else
    {
        return findSet(parent[i]);
    }
}

void Graph::uniteSet(int u, int v)
{
    parent[u] = parent[v];
}

int main()
{
    setlocale (LC_ALL, "Russian");

    Graph myGraph(8);

    myGraph.addEdge(0, 1, 2);
    myGraph.addEdge(0, 3, 4);
    myGraph.addEdge(0, 6, 6);
    myGraph.addEdge(1, 2, 1);
    myGraph.addEdge(1, 3, 1);
    myGraph.addEdge(1, 4, 2);
    myGraph.addEdge(2, 5, 7);
    myGraph.addEdge(3, 5, 5);
    myGraph.addEdge(3, 6, 1);
    myGraph.addEdge(4, 6, 2);
    myGraph.addEdge(4, 7, 2);
    myGraph.addEdge(5, 6, 1);
    myGraph.addEdge(6, 7, 2);

    myGraph.kruskalMethod();

    myGraph.print();

    return 0;
}