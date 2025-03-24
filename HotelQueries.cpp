// Range Queries
// Maximum Segment Tree Lower Bound
// https://cses.fi/problemset/task/1143/
#include <bits/stdc++.h>
using namespace std;

template<typename T>
struct MaxSegTree 
{
    int n = 1;
    vector<T> tree;
    MaxSegTree(const vector<T>& v) 
    {
        while (n < v.size()) n <<= 1;
        tree.resize(n << 1, 0);
        for (int i = 0; i < v.size(); i ++) tree[n + i] = v[i];
        for (int i = n - 1; i > 0; i --) tree[i] = max(tree[i << 1], tree[(i << 1) + 1]);   
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
                res = max(res, tree[l]);
                l ++;
            }
            if (!(r & 1)) 
            {
                res = max(res, tree[r]);
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
            tree[i] = max(tree[i << 1], tree[(i << 1) + 1]);
        }
    }
    T get(int i) 
    {
        return tree[i + n];
    }
    int find(T x) 
    {
        int i = 1;
        if (tree[i] < x) return -1;
        while (i < n)
        {
            if (tree[i << 1] >= x) i <<= 1;
            else i = (i << 1) + 1;
        }
        return i - n;
    }
};

int main() 
{
    ios::sync_with_stdio(false); 
    cin.tie(nullptr);
    int n, m;
    cin >> n >> m;
    vector<long long> h(n);
    for (int i = 0; i < n; i ++) cin >> h[i];
    MaxSegTree<long long> tree(h);
    for (int i = 0; i < m; i ++)
    {
        long long r;
        cin >> r;
        int idx = tree.find(r);
        if (idx == -1) cout << 0 << ' ';
        else 
        {
            cout << idx + 1 << ' ';
            tree.update(idx, tree.get(idx) - r);
        }
    }
    return 0;
}
