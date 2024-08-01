//https://cses.fi/problemset/task/1084
#include <bits/stdc++.h>
using namespace std;

void solve() {
    int n, m, k;
    cin >> n >> m >> k;
    vector<int> a(n), b(m);
    for(int i = 0; i < n; i ++) {
        cin >> a[i];
    }
    for(int i = 0; i < m; i ++) {
        cin >> b[i];
    }
    sort(a.begin(), a.end());
    sort(b.begin(), b.end());
    int ans = 0, j = 0;
    for(int i = 0; i < m; i ++) {
        while(j < n - 1 && a[j] < b[i] - k) j ++;
        if(b[i] + k >= a[j] && b[i] - k <= a[j]) {
            ans ++;
            j ++;
        }
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
