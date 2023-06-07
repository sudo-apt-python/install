#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

struct Edge
{
    int src, dest, weight;
    Edge(int src, int dest, int weight) : src(src), dest(dest), weight(weight) {}
};

bool compareEdges(const Edge &a, const Edge &b)
{
    return a.weight < b.weight;
}

int findParent(vector<int> &parent, int vertex)
{
    if (parent[vertex] == -1)
        return vertex;
    return findParent(parent, parent[vertex]);
}

void unionSets(vector<int> &parent, int x, int y)
{
    parent[x] = y;
}

void kruskalMST(vector<Edge> &edges, int V)
{
    vector<int> parent(V, -1);
    vector<Edge> mst;

    sort(edges.begin(), edges.end(), compareEdges);

    for (const Edge &edge : edges)
    {
        int srcParent = findParent(parent, edge.src);
        int destParent = findParent(parent, edge.dest);

        if (srcParent != destParent)
        {
            mst.push_back(edge);
            unionSets(parent, srcParent, destParent);
        }
    }

    cout << "Minimum Spanning Tree:\n";
    for (const Edge &edge : mst)
    {
        cout << edge.src << " -- " << edge.dest << "   Weight: " << edge.weight << "\n";
    }
}

int main()
{
    int V, E;
    cout << "Enter the number of vertices: ";
    cin >> V;
    cout << "Enter the number of edges: ";
    cin >> E;

    vector<Edge> edges;
    edges.reserve(E);

    for (int i = 0; i < E; i++)
    {
        int src, dest, weight;
        cout << "Enter edge " << i + 1 << " (source, destination, weight): ";
        cin >> src >> dest >> weight;
        edges.emplace_back(src, dest, weight);
    }

    kruskalMST(edges, V);

    return 0;
}
