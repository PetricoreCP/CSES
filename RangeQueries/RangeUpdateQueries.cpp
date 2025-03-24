// Range Queries
// Fenwick Tree Difference Array Range Sums
// https://cses.fi/problemset/task/1651
#include <bits/stdc++.h>
using namespace std;

template<typename T>
struct FenTree
{
    int n;
    vector<T> bit;
    FenTree(const vector<T>& v)  
    {
        n = v.size() + 1;
        bit.resize(n);
        for (int i = 1; i < n; i ++) bit[i] = v[i - 1];
        for (int i = 1; i < n; i ++) 
        {
            int p = i + (i & (-i));
            if (p < n) bit[p] += bit[i];
        }
    }
    void add(int i, T x) 
    {
        while (i < n) 
        {
            bit[i] += x;
            i += i & (-i);
        }
    }
    T prefix(int i) 
    {
        T res = 0;
        while (i > 0) 
        {
            res += bit[i];
            i -= (i & -i);
        }
        return res;
    }
    T query(int l, int r)
    {
        return prefix(r) - prefix(l - 1);
    }
};

int main() 
{
    ios::sync_with_stdio(false); 
    cin.tie(nullptr);
    int n, q;
    cin >> n >> q;
    vector<long long> v(n);
    for (int i = 0; i < n; i ++) cin >> v[i];
    vector<long long> difference(n); difference[0] = v[0];
    for (int i = 1; i < n; i ++) difference[i] = v[i] - v[i - 1];
    FenTree<long long> bit(difference);
    while (q --) 
    {
        int t;
        cin >> t;
        if (t == 1) 
        {
            int l, r;
            cin >> l >> r;
            long long x;
            cin >> x;
            bit.add(l, x);
            if (r + 1 <= n) bit.add(r + 1, -x);
        }
        else 
        {
            int k;
            cin >> k;
            cout << bit.prefix(k) << '\n';
        }
    }
    return 0;
}
