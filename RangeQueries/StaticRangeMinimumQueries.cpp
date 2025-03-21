// Range Queries
// Sparse Table Minimum Queries
// https://cses.fi/problemset/task/1647
#include <bits/stdc++.h>
using namespace std;

template<typename T>
struct MinSparseTable {
    int n;
    vector<vector<T>> st;
    vector<int> log;
    MinSparseTable(const vector<T>& v) {
        n = v.size();
        log.resize(n + 1);
        for (int i = 2; i <= n; i ++) {
            log[i] = log[i / 2] + 1;
        }
        st.assign(n, vector<T>(log[n] + 1));
        for (int i = 0; i < n; i ++) {
            st[i][0] = v[i];
        }
        for (int j = 1; j <= log[n]; j ++) {
            for (int i = 0; i + (1 << j) <= n; i ++) {
                st[i][j] = min(st[i][j - 1], st[i + (1 << (j - 1))][j - 1]);
            }
        }
    }
    T query(int l, int r) {
        int k = log[r - l + 1];
        return min(st[l][k], st[r - (1 << k) + 1][k]);
    }
};

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int n, q;
    cin >> n >> q;
    vector<long long> v(n);
    for (int i = 0; i < n; i ++) {
        cin >> v[i];
    }
    MinSparseTable<long long> st(v);
    while (q --) {
        int l, r;
        cin >> l >> r;
        cout << st.query(l - 1, r - 1) << '\n';
    }
    return 0;
}
