// Range Queries
// Fenwick Tree Lower Bound
// https://cses.fi/problemset/task/1749
#include <bits/stdc++.h>
using namespace std;

template<typename T>
struct FenTree
{
    int n, msb = 1;
    vector<T> bit;
    FenTree(int sz) 
    {
        n = sz + 1;
        bit.resize(n);
        while ((msb << 1) < n) msb <<= 1;
    }
    FenTree(const vector<T>& v) : FenTree(v.size())
    {
        for (int i = 1; i < n; i ++) bit[i] = v[i - 1];
        for (int i = 1; i < n; i ++) 
        {
            int p = i + (i & (-i));
            if (p < n) bit[p] += bit[i];
        }
    }
    void update(int i, T x) 
    {
        T delta = x - query(i, i); 
        add(i, delta);
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
    int find(T x) 
    {
        if (prefix(n - 1) < x) return -1;
        int i = 0;
        T curr = 0;
        for (int b = msb; b > 0; b >>= 1) 
        {
            int j = i | b;
            if (j < n && curr + bit[j] < x)
            {
                curr += bit[j];
                i = j;
            }
        }
        return i + 1;
    }
};

int main() 
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int n; 
    cin >> n;
    vector<long long> v(n);
    vector<int> activity(n);
    for (int i = 0; i < n; i ++) activity[i] = 1;
    FenTree<int> bit(activity);
    for (int i = 0; i < n; i ++) cin >> v[i];
    for (int i = 0; i < n; i ++) 
    {
        int p;
        cin >> p;
        int idx = bit.find(p);
        cout << v[idx - 1] << ' ';
        bit.update(idx, 0);
    }
    return 0;
}
