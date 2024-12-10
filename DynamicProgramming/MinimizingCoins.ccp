//https://cses.fi/problemset/task/1634
#include <bits/stdc++.h>
using namespace std;

constexpr int INF = 1E9;

int32_t main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int n, x;
    cin >> n >> x;
    vector<int> c(n);
    for(int i = 0; i < n; i ++) {
        cin >> c[i];
    }
    vector<int> dp(x + 1, INF);
    dp[0] = 0;
    for(int i = 0; i < x; i ++) {
        for(int j = 0; j < n; j ++) {
            if(i + c[j] <= x) {
                dp[i + c[j]] = min(dp[i + c[j]], dp[i] + 1);
            }
        }
    }
    cout << (dp[x] == INF ? -1 : dp[x]);
    return 0;
}
