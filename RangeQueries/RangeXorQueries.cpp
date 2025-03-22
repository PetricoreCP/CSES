// Range Queries
// Prefix Xor Array
// https://cses.fi/problemset/task/1650
#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int n, q;
    cin >> n >> q;
    vector<long long> v(n);
    for (int i = 0; i < n; i ++) {
        cin >> v[i];
    }
    vector<long long> prefixXor(n + 1);
    for (int i = 0; i < n; i ++) {
        prefixXor[i + 1] = prefixXor[i] ^ v[i];
    }
    while (q --) {
        int l, r;
        cin >> l >> r;
        cout << (prefixXor[r] ^ prefixXor[l - 1]) << '\n';
    }
    return 0;
}
