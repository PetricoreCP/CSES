//https://cses.fi/problemset/task/1635
#include <bits/stdc++.h>
using namespace std;

constexpr int MOD = 1E9 + 7;

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
    for(int i = 0; i < x; i ++) {
        for(int j = 0; j < n; j ++) {
            if(i + c[j] <= x) {
                dp[i + c[j]] += dp[i];
                dp[i + c[j]] %= MOD;                
            }
        }
    }
    cout << dp[x];
    return 0;
}
