#include <iostream>
#include <vector>
#include <algorithm>
#include <climits>

using namespace std;

int calculateDistance(const vector<vector<int>> &graph, const vector<int> &path)
{
    int distance = 0;
    int n = path.size();
    for (int i = 0; i < n - 1; ++i)
    {
        int src = path[i];
        int dest = path[i + 1];
        distance += graph[src][dest];
    }
    distance += graph[path[n - 1]][path[0]];
    return distance;
}

vector<int> tspBruteForce(const vector<vector<int>> &graph)
{
    int n = graph.size(); // Number of cities
    vector<int> cities(n);
    for (int i = 0; i < n; ++i)
    {
        cities[i] = i;
    }
    int minDistance = INT_MAX;
    vector<int> optimalPath;
    do
    {
        int currentDistance = calculateDistance(graph, cities);
        if (currentDistance < minDistance)
        {
            minDistance = currentDistance;
            optimalPath = cities;
        }
    } while (next_permutation(cities.begin() + 1, cities.end()));
    return optimalPath;
}

int main()
{
    int n; // Number of cities
    cout << "Enter the number of cities: ";
    cin >> n;
    vector<vector<int>> graph(n, vector<int>(n));
    cout << "Enter the distance matrix:\n";
    for (int i = 0; i < n; ++i)
    {
        for (int j = 0; j < n; ++j)
        {
            cin >> graph[i][j];
        }
    }
    vector<int> optimalPath = tspBruteForce(graph);
    cout << "Optimal Path: ";
    for (int city : optimalPath)
    {
        cout << city << " ";
    }
    cout << optimalPath[0] << "\n"; // Return to the starting city
    cout << "Total Distance: " << calculateDistance(graph, optimalPath) << "\n";
    return 0;
}
