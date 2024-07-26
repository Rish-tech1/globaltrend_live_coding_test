#include <iostream>
#include <vector>

using namespace std;

int knapsack(const vector<int>& weights, const vector<int>& values, int capacity) {
    int n = weights.size();
    int dp[n + 1][capacity + 1];

    for (int i = 0; i <= n; i++) {
        for (int w = 0; w <= capacity; w++) {
            if (i == 0 || w == 0) {
                dp[i][w] = 0;
            } else if (weights[i - 1] <= w) {
                dp[i][w] = max(values[i - 1] + dp[i - 1][w - weights[i - 1]], dp[i - 1][w]);
            } else {
                dp[i][w] = dp[i - 1][w];
            }
        }
    }

    return dp[n][capacity];
}

int main() {
    vector<int> weights = {1, 2, 3};
    vector<int> values = {10, 15, 40};
    int capacity = 6;

    int max_value = knapsack(weights, values, capacity);
    cout << "Maximum value: " << max_value << endl;

    return 0;
}
