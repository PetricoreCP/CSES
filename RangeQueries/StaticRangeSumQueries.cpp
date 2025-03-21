// Range Queries
// Prefix Sum Array
// https://cses.fi/problemset/task/1646
#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int n, q;
    cin >> n >> q;
    vector<long long> v(n + 1);
    for (int i = 1; i <= n; i ++) {
        cin >> v[i];
    }
    vector<long long> prefixSum(n + 1);
    for (int i = 1; i <= n; i ++) {
        prefixSum[i] = prefixSum[i - 1] + v[i];
    }
    while (q --) {
        int l, r;
        cin >> l >> r;
        cout << prefixSum[r] - prefixSum[l - 1] << '\n';
    }
    return 0;
}
