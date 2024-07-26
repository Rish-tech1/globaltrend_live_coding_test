#include <iostream>
#include <vector>
#include <string>
using namespace std;

int longestCommonSubsequence(string str1, string str2) {
    int m = str1.size();
    int n = str2.size();
    
   
    vector<vector<int>> dp(m + 1, vector<int>(n + 1, 0));
    
    for (int i = 1; i <= m; ++i) {
        for (int j = 1; j <= n; ++j) {
            if (str1[i - 1] == str2[j - 1]) {
                dp[i][j] = dp[i - 1][j - 1] + 1;
            } else {
                dp[i][j] = max(dp[i - 1][j], dp[i][j - 1]);
            }
        }
    }
    
    
    return dp[m][n];
}

int main() {
    string str1 = "abcde";
    string str2 = "ace";
    
    cout << "Length of LCS: " << longestCommonSubsequence(str1, str2) << endl;
    return 0;
}
