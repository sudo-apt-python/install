#include <iostream>
#include <vector>
#include <queue>

using namespace std;

void dfs(const vector<vector<int>>& graph, vector<bool>& visited, int vertex) {
    visited[vertex] = true;
    for (int neighbor : graph[vertex]) {
        if (!visited[neighbor]) {
            dfs(graph, visited, neighbor);
        }
    }
}

bool isConnectedDFS(const vector<vector<int>>& graph, int V) {
    vector<bool> visited(V, false);
    dfs(graph, visited, 0); // Start DFS from vertex 0

    for (bool v : visited) {
        if (!v) {
            return false; // If any vertex is not visited, the graph is not connected
        }
    }
    return true; // All vertices are visited, so the graph is connected
}

bool isConnectedBFS(const vector<vector<int>>& graph, int V) {
    vector<bool> visited(V, false);
    queue<int> q;
    q.push(0); // Start BFS from vertex 0
    visited[0] = true;

    while (!q.empty()) {
        int vertex = q.front();
        q.pop();

        for (int neighbor : graph[vertex]) {
            if (!visited[neighbor]) {
                q.push(neighbor);
                visited[neighbor] = true;
            }
        }
    }

    for (bool v : visited) {
        if (!v) {
            return false; // If any vertex is not visited, the graph is not connected
        }
    }
    return true; // All vertices are visited, so the graph is connected
}

int main() {
    int V, E;
    cout << "Enter the number of vertices: ";
    cin >> V;
    cout << "Enter the number of edges: ";
    cin >> E;

    vector<vector<int>> graph(V);
    cout << "Enter the edges (u, v):\n";
    for (int i = 0; i < E; ++i) {
        int u, v;
        cin >> u >> v;
        graph[u].push_back(v);
        graph[v].push_back(u);
    }

    bool connectedDFS = isConnectedDFS(graph, V);
    bool connectedBFS = isConnectedBFS(graph, V);

    if (connectedDFS) {
        cout << "The graph is connected (DFS)\n";
    } else {
        cout << "The graph is not connected (DFS)\n";
    }

    if (connectedBFS) {
        cout << "The graph is connected (BFS)\n";
    } else {
        cout << "The graph is not connected (BFS)\n";
    }

    return 0;
}
