//https://cses.fi/problemset/task/1633
#include <bits/stdc++.h>
using namespace std;

constexpr int MOD = 1E9 + 7;

int32_t main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int n;
    cin >> n;
    vector<int> dp(n + 6);
    dp[0] = 1;
    for(int i = 0; i < n; i ++) {
        for(int j = 1; j <= 6; j ++) {
            dp[i + j] += dp[i];
            dp[i + j] %= MOD;
        }
    }
    cout << dp[n];
    return 0;
}
