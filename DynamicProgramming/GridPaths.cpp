//https://cses.fi/problemset/task/1638
#include <bits/stdc++.h>
using namespace std;

constexpr int MOD = 1E9 + 7;

int32_t main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int n;
    cin >> n;
    vector<string> grid(n);
    for(int i = 0; i < n; i ++) {
        cin >> grid[i];
    }
    vector<vector<int>> dp(n, vector<int>(n));
    dp[0][0] = 1;
    for(int i = 0; i < n; i ++) {
        for(int j = 0; j < n; j ++) {
            if(grid[i][j] == '*') continue;
            if(i < n - 1) {
                dp[i + 1][j] += dp[i][j];
                dp[i + 1][j] %= MOD;
            }
            if(j < n - 1) {
                dp[i][j + 1] += dp[i][j];
                dp[i][j + 1] %= MOD;
            }  
        }
    }
    cout << (grid[n - 1][n - 1] == '*' ? 0 : dp[n - 1][n - 1]);
    return 0;
}
