//https://cses.fi/problemset/task/1637
#include <bits/stdc++.h>
using namespace std;

constexpr int INF = 1E9;

int32_t main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int n;
    cin >> n;
    vector<int> dp(n + 1, INF);
    dp[n] = 0;
    for(int i = n; i > 0; i --) {
        string s = to_string(i);
        for(auto &c : s) {
            if(n - (c - '0') >= 0) {
                dp[i - (c - '0')] = min(dp[i - (c - '0')], dp[i] + 1);
            }
        }
    }
    cout << dp[0];
    return 0;
}
