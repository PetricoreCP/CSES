//https://cses.fi/problemset/task/1628/
#include <bits/stdc++.h>
using namespace std;

void solve() {
    int n;
    long long x;
    cin >> n >> x;
    int a = n / 2, b = n - a;
    vector<long long> f(a), s(b);
    for(int i = 0; i < a; i ++) {
        cin >> f[i];
    }
    for(int i = 0; i < b; i ++) {
        cin >> s[i];
    }
    vector<long long> left, right;
    for(int mask = 0; mask < (1 << a); mask ++) {
        long long sum = 0;
        for(int i = 0; i < a; i ++) {
            if((mask >> i) & 1) {
                sum += f[i];
            }
        }
        left.push_back(sum);
    }
    for(int mask = 0; mask < (1 << b); mask ++) {
        long long sum = 0;
        for(int i = 0; i < b; i ++) {
            if((mask >> i) & 1) {
                sum += s[i];
            }
        }
        right.push_back(sum);
    }
    sort(left.begin(), left.end());
    sort(right.begin(), right.end());
    long long ans = 0;
    for(auto &e : left) {
        auto itl = lower_bound(right.begin(), right.end(), x - e) - right.begin();
        auto itr = upper_bound(right.begin(), right.end(), x - e) - right.begin();
        ans += itr - itl;
    }
    cout << ans;
}

int main() {
    ios::sync_with_stdio(false); 
    cin.tie(nullptr);
    int tc = 1;
    //cin >> tc;
    while(tc --) solve();
    return 0;
}
