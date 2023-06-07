// 0/1 Knapsack Problem:
#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

struct Item
{
    int weight;
    int profit;
};

bool compare(Item item1, Item item2)
{
    double ratio1 = static_cast<double>(item1.profit) / item1.weight;
    double ratio2 = static_cast<double>(item2.profit) / item2.weight;
    return ratio1 > ratio2;
}

int knapsack01(int W, vector<Item> &items)
{
    int n = items.size();
    sort(items.begin(), items.end(), compare);

    vector<vector<int>> dp(n + 1, vector<int>(W + 1, 0));

    for (int i = 1; i <= n; i++)
    {
        for (int w = 1; w <= W; w++)
        {
            if (items[i - 1].weight <= w)
            {
                dp[i][w] = max(items[i - 1].profit + dp[i - 1][w - items[i - 1].weight], dp[i - 1][w]);
            }
            else
            {
                dp[i][w] = dp[i - 1][w];
            }
        }
    }

    vector<int> chosenItems;
    int i = n, j = W;
    while (i > 0 && j > 0)
    {
        if (dp[i][j] != dp[i - 1][j])
        {
            chosenItems.push_back(i - 1);
            j -= items[i - 1].weight;
        }
        i--;
    }
    reverse(chosenItems.begin(), chosenItems.end());

    cout << "Items selected in sequence: ";
    for (int i = 0; i < chosenItems.size(); i++)
    {
        cout << "I" << chosenItems[i] + 1 << " ";
    }
    cout << endl;

    return dp[n][W];
}

int main()
{
    int W;
    cout << "Enter the Capacity of the Knapsack(Bag): ";
    cin >> W;

    int n;
    cout << "Enter the Number of Items: ";
    cin >> n;

    vector<Item> items(n);

    cout << "Enter the Weight and Profit of Each Item:\n";
    for (int i = 0; i < n; i++)
    {
        cin >> items[i].weight >> items[i].profit;
    }

    int maxValue = knapsack01(W, items);

    cout << "Maximum Profit that can be Obtained: " << maxValue << endl;

    return 0;
}

// Fractional Knapsack Problem:

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

struct Item
{
    int weight;
    int profit;
};

bool compare(Item item1, Item item2)
{
    double ratio1 = static_cast<double>(item1.profit) / item1.weight;
    double ratio2 = static_cast<double>(item2.profit) / item2.weight;
    return ratio1 > ratio2;
}

double fractionalKnapsack(int W, vector<Item> &items)
{
    int n = items.size();
    sort(items.begin(), items.end(), compare);

    double totalProfit = 0.0;

    for (int i = 0; i < n; i++)
    {
        if (items[i].weight <= W)
        {
            totalProfit += items[i].profit;
            W -= items[i].weight;
        }
        else
        {
            double fraction = static_cast<double>(W) / items[i].weight;
            totalProfit += fraction * items[i].profit;
            break;
        }
    }

    cout << "Items selected in sequence: ";
    for (int i = 0; i < n; i++)
    {
        if (items[i].weight <= W)
        {
            cout << "I" << i + 1 << " ";
            W -= items[i].weight;
        }
        else
        {
            double fraction = static_cast<double>(W) / items[i].weight;
            cout << "I" << i + 1 << " (partial, fraction = " << fraction << ") ";
            break;
        }
    }
    cout << endl;

    return totalProfit;
}

int main()
{
    int W;
    cout << "Enter the Capacity of the Knapsack(Bag): ";
    cin >> W;

    int n;
    cout << "Enter the Number of Items: ";
    cin >> n;

    vector<Item> items(n);

    cout << "Enter the Weight and Profit of Each Item:\n";
    for (int i = 0; i < n; i++)
    {
        cin >> items[i].weight >> items[i].profit;
    }

    double maxValue = fractionalKnapsack(W, items);

    cout << "Maximum Profit that can be Obtained: " << maxValue << endl;

    return 0;
}
