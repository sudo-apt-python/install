// Fractional Knapsack:

#include <iostream>
#include <vector>

using namespace std;

struct Item
{
    int profit;
    int weight;
    Item(int profit, int weight) : profit(profit), weight(weight) {}
};

bool compare(Item a, Item b)
{
    double ratioA = (double)a.profit / a.weight;
    double ratioB = (double)b.profit / b.weight;
    return ratioA > ratioB;
}

double fractionalKnapsack(int W, vector<Item> &items)
{
    sort(items.begin(), items.end(), compare);
    double totalProfit = 0.0;
    for (const Item &item : items)
    {
        if (W >= item.weight)
        {
            totalProfit += item.profit;
            W -= item.weight;
        }
        else
        {
            totalProfit += (double)W / item.weight * item.profit;
            break;
        }
    }
    return totalProfit;
}

int main()
{
    int W;
    cout << "Enter the capacity of the knapsack: ";
    cin >> W;

    int n;
    cout << "Enter the number of items: ";
    cin >> n;

    vector<Item> items;
    cout << "Enter the profit and weight of each item:\n";
    for (int i = 0; i < n; ++i)
    {
        int profit, weight;
        cin >> profit >> weight;
        items.push_back(Item(profit, weight));
    }

    double maxProfit = fractionalKnapsack(W, items);
    cout << "Maximum Profit: " << maxProfit << endl;

    return 0;
}

// 0/1 Knapsack:

#include <iostream>
#include <vector>

using namespace std;

int max(int a, int b)
{
    return (a > b) ? a : b;
}

int knapsack(int W, vector<int> &wt, vector<int> &val, int n)
{
    vector<vector<int>> dp(n + 1, vector<int>(W + 1, 0));

    for (int i = 1; i <= n; i++)
    {
        for (int w = 1; w <= W; w++)
        {
            if (wt[i - 1] <= w)
            {
                dp[i][w] = max(val[i - 1] + dp[i - 1][w - wt[i - 1]], dp[i - 1][w]);
            }
            else
            {
                dp[i][w] = dp[i - 1][w];
            }
        }
    }
    return dp[n][W];
}

int main()
{
    int W;
    cout << "Enter the capacity of the knapsack: ";
    cin >> W;

    int n;
    cout << "Enter the number of items: ";
    cin >> n;

    vector<int> wt(n);
    vector<int> val(n);

    cout << "Enter the weight and value of each item:\n";
    for (int i = 0; i < n; i++)
    {
        cin >> wt[i] >> val[i];
    }

    int maxProfit = knapsack(W, wt, val, n);
    cout << "Maximum Profit: " << maxProfit << endl;

    return 0;
}
