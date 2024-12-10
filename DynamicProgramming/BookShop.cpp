//https://cses.fi/problemset/task/1158
#include <bits/stdc++.h>
using namespace std;

int32_t main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int n, x;
    cin >> n >> x;
    vector<int> h(n);
    for(int i = 0; i < n; i ++) {
        cin >> h[i];
    }
    vector<int> s(n);
    for(int i = 0; i < n; i ++) {
        cin >> s[i];
    }
    vector<int> dp(x + 1);
    for(int i = 0; i < n; i ++) {
        for(int j = x; j >= h[i]; j --) {
            dp[j] = max(dp[j], dp[j - h[i]] + s[i]);
        }
    }
    cout << dp[x];
    return 0;
}
