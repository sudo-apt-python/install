#include <iostream>
#include <vector>
#include <queue>
void dfs(const std::vector<std::vector<int>>& graph, std::vector<bool>& visited, int vertex) {
    visited[vertex] = true;
    for (int neighbor : graph[vertex]) {
        if (!visited[neighbor]) {
            dfs(graph, visited, neighbor);
        }
    }
}
bool isConnectedDFS(const std::vector<std::vector<int>>& graph, int V) {
    std::vector<bool> visited(V, false);
    dfs(graph, visited, 0);
    for (bool isVisited : visited) {
        if (!isVisited) {
            return false;
        }
    }
    return true;
}
bool isConnectedBFS(const std::vector<std::vector<int>>& graph, int V) {
    std::vector<bool> visited(V, false);
    std::queue<int> q;
    visited[0] = true;
    q.push(0);

    while (!q.empty()) {
        int vertex = q.front();
        q.pop();
        for (int neighbor : graph[vertex]) {
            if (!visited[neighbor]) {
                visited[neighbor] = true;
                q.push(neighbor);
            }
        }
    }
    for (bool isVisited : visited) {
        if (!isVisited) {
            return false;
        }
    }
    return true;
}
int main() {
    int V, E;
    std::cout << "Enter the number of vertices: ";
    std::cin >> V;
    std::cout << "Enter the number of edges: ";
    std::cin >> E;
    std::vector<std::vector<int>> graph(V);
    std::cout << "Enter the edges (u, v):\n";
    for (int i = 0; i < E; ++i) {
        int u, v;
        std::cin >> u >> v;
        graph[u].push_back(v);
        graph[v].push_back(u);
    }
    bool isGraphConnectedDFS = isConnectedDFS(graph, V);
    bool isGraphConnectedBFS = isConnectedBFS(graph, V);
    if (isGraphConnectedDFS) {
        std::cout << "The graph is connected using DFS.\n";
    } else {
        std::cout << "The graph is not connected using DFS.\n";
    }
    if (isGraphConnectedBFS) {
        std::cout << "The graph is connected using BFS.\n";
    } else {
        std::cout << "The graph is not connected using BFS.\n";
    }
    return 0;
}
