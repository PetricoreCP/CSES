//https://cses.fi/problemset/task/1636
#include <bits/stdc++.h>
using namespace std;

constexpr int MOD = 1e9 + 7;

int32_t main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int n, x;
    cin >> n >> x;
    vector<int> c(n);
    for(int i = 0; i < n; i ++) {
        cin >> c[i];
    }
    vector<int> dp(x + 1);
    dp[0] = 1;
    for(int j = 0; j < n; j ++) {
        for(int i = 0; i < x; i ++) {
            if(i + c[j] <= x) {
                dp[i + c[j]] += dp[i];
                dp[i + c[j]] %= MOD;
            }
        }
    }
    cout << dp[x];
    return 0;
}