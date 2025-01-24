#include <iostream>
using namespace std;

struct Item {
    int profit;
    int weight;
};

void knapsack(int capacity, int n, Item items[]) {
    int dp[n + 1][capacity + 1];

    for (int i = 0; i <= n; i++) {
        for (int w = 0; w <= capacity; w++) {
            if (i == 0 || w == 0) {
                dp[i][w] = 0;
            } else if (items[i - 1].weight <= w) {
                dp[i][w] = max(dp[i - 1][w],
                               items[i - 1].profit + dp[i - 1][w - items[i - 1].weight]);
            } else {
                dp[i][w] = dp[i - 1][w];
            }
        }
    }

    cout << "Maximum Profit: " << dp[n][capacity] << endl;

    int W = capacity;
    cout << "Selected items: ";
    for (int i = n; i > 0 && W > 0; i--) {
        if (dp[i][W] != dp[i - 1][W]) {
            cout << i << " ";
            W -= items[i - 1].weight;
        }
    }
    cout << endl;
}

int main() {
    int n, capacity;
    cout << "Enter the number of items: ";
    cin >> n;

    Item items[n];
    cout << "Enter the profit of items:\n";
    for (int i = 0; i < n; i++) {
        cin >> items[i].profit;
    }

    cout << "Enter the weights of the items:\n";
    for (int i = 0; i < n; i++) {
        cin >> items[i].weight;
    }

    cout << "Enter the capacity of the knapsack: ";
    cin >> capacity;

    knapsack(capacity, n, items);

    return 0;
}