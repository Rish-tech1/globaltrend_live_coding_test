#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;


int knapsack(const vector<int>& weights, const vector<int>& values, int capacity) {
    int n = weights.size();
    vector<vector<int>> dp(n + 1, vector<int>(capacity + 1, 0));
    
    
    for (int i = 1; i <= n; ++i) {
        for (int w = 0; w <= capacity; ++w) {
            if (weights[i - 1] <= w) {
                dp[i][w] = max(dp[i - 1][w], dp[i - 1][w - weights[i - 1]] + values[i - 1]);
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
    
    int maxValue = knapsack(weights, values, capacity);
    
    cout << "Maximum value that can be obtained: " << maxValue << endl;
    
    return 0;
}
