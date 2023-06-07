#include <iostream>
#include <vector>

using namespace std;

int knapsack(int W, const vector<int>& weights, const vector<int>& values, int n) {
    vector<vector<int>> dp(n + 1, vector<int>(W + 1, 0));
    for (int i = 1; i <= n; ++i) {
        for (int w = 1; w <= W; ++w) {
            if (weights[i - 1] <= w) {
                dp[i][w] = max(values[i - 1] + dp[i - 1][w - weights[i - 1]], dp[i - 1][w]);
            } else {
                dp[i][w] = dp[i - 1][w];
            }
        }
    }
    return dp[n][W];
}

int main() {
    int W;
    cout << "Enter the capacity of the knapsack: ";
    cin >> W;
    int n;
    cout << "Enter the number of items: ";
    cin >> n;
    vector<int> weights(n);
    vector<int> values(n);
    cout << "Enter the weight and value of each item:\n";
    for (int i = 0; i < n; ++i) {
        cin >> weights[i] >> values[i];
    }
    int maxValue = knapsack(W, weights, values, n);
    cout << "Maximum value that can be obtained: " << maxValue << endl;
    return 0;
}
