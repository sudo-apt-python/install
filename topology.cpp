#include <bits/stdc++.h>

using namespace std;

void dfs(const vector<vector<int>> &graph, vector<bool> &visited, stack<int> &result, int vertex)
{
    visited[vertex] = true;
    for (int neighbor : graph[vertex])
    {
        if (!visited[neighbor])
        {
            dfs(graph, visited, result, neighbor);
        }
    }
    result.push(vertex);
}

vector<int> topologicalSortDFS(const vector<vector<int>> &graph, int V)
{
    vector<bool> visited(V, false);
    stack<int> result;
    for (int i = 0; i < V; ++i)
    {
        if (!visited[i])
        {
            dfs(graph, visited, result, i);
        }
    }
    vector<int> topologicalOrder;
    while (!result.empty())
    {
        topologicalOrder.push_back(result.top());
        result.pop();
    }
    return topologicalOrder;
}

vector<int> topologicalSortBFS(const vector<vector<int>> &graph, int V)
{
    vector<int> inDegree(V, 0);
    for (const auto &neighbors : graph)
    {
        for (int neighbor : neighbors)
        {
            inDegree[neighbor]++;
        }
    }
    queue<int> q;
    for (int i = 0; i < V; ++i)
    {
        if (inDegree[i] == 0)
        {
            q.push(i);
        }
    }
    vector<int> topologicalOrder;
    while (!q.empty())
    {
        int vertex = q.front();
        q.pop();
        topologicalOrder.push_back(vertex);
        for (int neighbor : graph[vertex])
        {
            inDegree[neighbor]--;
            if (inDegree[neighbor] == 0)
            {
                q.push(neighbor);
            }
        }
    }
    return topologicalOrder;
}

int main()
{
    int V, E;
    cout << "Enter the number of vertices: ";
    cin >> V;
    cout << "Enter the number of edges: ";
    cin >> E;

    vector<vector<int>> graph(V);

    cout << "Enter the edges (u, v):\n";
    for (int i = 0; i < E; ++i)
    {
        int u, v;
        cin >> u >> v;
        graph[u].push_back(v);
    }

    vector<int> topologicalOrderDFS = topologicalSortDFS(graph, V);
    vector<int> topologicalOrderBFS = topologicalSortBFS(graph, V);

    cout << "Topological order using DFS: ";
    for (int vertex : topologicalOrderDFS)
    {
        cout << vertex << " ";
    }
    cout << "\n";

    cout << "Topological order using BFS: ";
    for (int vertex : topologicalOrderBFS)
    {
        cout << vertex << " ";
    }
    cout << "\n";

    return 0;
}