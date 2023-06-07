#include <iostream>
#include <vector>
int knapsack(int W, const std::vector<int>& weights, const std::vector<int>& values, int n) {
    std::vector<std::vector<int>> dp(n + 1, std::vector<int>(W + 1, 0));
    for (int i = 1; i <= n; ++i) {
        for (int w = 1; w <= W; ++w) {
            if (weights[i - 1] <= w) {
                dp[i][w] = std::max(values[i - 1] + dp[i - 1][w - weights[i - 1]], dp[i - 1][w]);
            } else {
                dp[i][w] = dp[i - 1][w];
            }
        }
    }
    return dp[n][W];
}
int main() {
    int W;
    std::cout << "Enter the capacity of the knapsack: ";
    std::cin >> W;
    int n;
    std::cout << "Enter the number of items: ";
    std::cin >> n;
    std::vector<int> weights(n);
    std::vector<int> values(n);
    std::cout << "Enter the weight and value of each item:\n";
    for (int i = 0; i < n; ++i) {
        std::cin >> weights[i] >> values[i];
 }
    int maxValue = knapsack(W, weights, values, n);
    std::cout << "Maximum value that can be obtained: " << maxValue << std::endl;
    return 0;
}
