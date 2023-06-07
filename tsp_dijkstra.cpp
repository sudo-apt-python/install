#include <iostream>
#include <vector>
#include <cmath>
#include <climits>
#include <algorithm>

using namespace std;

int findNearestCity(const vector<double> &distances, const vector<bool> &visited)
{
    int nearestCity = -1;
    double minDistance = INT_MAX;
    int n = distances.size();
    for (int i = 0; i < n; ++i)
    {
        if (!visited[i] && distances[i] < minDistance)
        {
            minDistance = distances[i];
            nearestCity = i;
        }
    }
    return nearestCity;
}

vector<int> tspDijkstra(const vector<vector<double>> &graph)
{
    int n = graph.size(); // Number of cities
    vector<bool> visited(n, false);
    vector<int> path;
    path.push_back(0); // Start from the first city
    visited[0] = true;

    for (int i = 0; i < n - 1; ++i)
    {
        int currentCity = path.back();
        double minDistance = INT_MAX;
        int nearestCity = -1;
        for (int j = 0; j < n; ++j)
        {
            if (!visited[j] && graph[currentCity][j] < minDistance)
            {
                minDistance = graph[currentCity][j];
                nearestCity = j;
            }
        }
        path.push_back(nearestCity);
        visited[nearestCity] = true;
    }
    return path;
}

int main()
{
    int n; // Number of cities
    cout << "Enter the number of cities: ";
    cin >> n;
    vector<vector<double>> graph(n, vector<double>(n, 0.0));
    cout << "Enter the distances between cities:\n";
    for (int i = 0; i < n; ++i)
    {
        for (int j = 0; j < n; ++j)
        {
            cin >> graph[i][j];
        }
    }
    vector<int> optimalPath = tspDijkstra(graph);
    cout << "Optimal Path: ";
    for (int city : optimalPath)
    {
        cout << city << " ";
    }
    cout << optimalPath[0] << "\n"; // Return to the starting city
    return 0;
}
