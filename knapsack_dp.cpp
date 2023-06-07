#include <bits/stdc++.h>
using namespace std;
int knapsack(int W, const vector<int> &weights, const vector<int> &profit, int n, vector<int> &chosenItems)
{
    vector<vector<int>> dp(n + 1, vector<int>(W + 1, 0));
    // Dynamic programming loop to fill the knapsack table
    for (int i = 1; i <= n; i++)
    {
        for (int w = 1; w <= W; w++)
        {
            if (weights[i - 1] <= w)
            {
                // If the current item can be included, calculate the maximum value
                // by either including or excluding the item
                dp[i][w] = max(profit[i - 1] + dp[i - 1][w - weights[i - 1]], dp[i - 1][w]);
            }
            else
            {
                // If the current item cannot be included, take the value from the previous row
                dp[i][w] = dp[i - 1][w];
            }
        }
    }
    // Backtracking to determine the chosen items
    int i = n, j = W;
    while (i > 0 && j > 0)
    {
        if (dp[i][j] != dp[i - 1][j])
        {
            // If the value changes compared to the previous row,
            // include the item in the chosen items list
            chosenItems.push_back(i - 1);
            j -= weights[i - 1]; // Reduce the remaining capacity of the knapsack
        }
        i--; // Move to the previous row
    }
    reverse(chosenItems.begin(), chosenItems.end()); // Reverse the order to show the sequence
    return dp[n][W];                        // Return the maximum profit that can be obtained
}
int main()
{
    int W;
    cout << "Enter the Capacity of the Knapsack(Bag): ";
    cin >> W;
    int n;
    cout << "Enter the Number of Items: ";
    cin >> n;
    vector<int> weights(n);
    vector<int> profit(n);
    cout << "Enter the Weight and Profit of Each Item:\n";
    for (int i = 0; i < n; i++)
    {
        cin >> weights[i] >> profit[i];
    }
    vector<int> chosenItems;
    int maxValue = knapsack(W, weights, profit, n, chosenItems);
    cout << "Maximum Profit that can be Obtained: " << maxValue << endl;
    cout << "Items selected in sequence: ";
    for (int i = 0; i < chosenItems.size(); i++)
    {
        cout << "I" << chosenItems[i] + 1 << " ";
    }
    cout << endl;
    return 0;
}