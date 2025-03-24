// Range Queries
// Segment Tree Sum Queries
// https://cses.fi/problemset/task/1648
#include <bits/stdc++.h>
using namespace std;

template<typename T>
struct SumSegTree 
{
    int n = 1;
    vector<T> tree;
    SumSegTree(const vector<T>& v) 
    {
        while (n < v.size()) n <<= 1;
        tree.resize(n << 1, 0);
        for (int i = 0; i < v.size(); i ++) tree[n + i + 1] = v[i];
        for (int i = n - 1; i > 0; i --) tree[i] = tree[i << 1] + tree[(i << 1) + 1];
    }
    T query(int l, int r) 
    {
        l += n;
        r += n;
        T res = 0;
        while (l <= r) 
        {
            if (l & 1) 
            {
                res += tree[l];
                l ++;
            }
            if (!(r & 1)) 
            {
                res += tree[r];
                r --;
            }
            l >>= 1;
            r >>= 1;
        }
        return res;
    }
    void update(int i, T x) 
    {
        i += n;
        tree[i] = x;
        while ((i >> 1) > 0) 
        {
            i >>= 1;
            tree[i] = tree[i << 1] + tree[(i << 1) + 1];
        }
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
    SumSegTree<long long> tree(v);
    while (q --) 
    {
        int t;
        cin >> t;
        if (t == 1) 
        {
            int i;
            long long x;
            cin >> i >> x;
            tree.update(i, x);
        }
        else 
        {
            int l, r;
            cin >> l >> r;
            cout << tree.query(l, r) << '\n';
        }
    }
    return 0;
}
