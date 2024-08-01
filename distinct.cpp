//https://cses.fi/problemset/task/1621/
#include <bits/stdc++.h>
using namespace std;
 
void solve() {
    int n;
    cin >> n;
    vector<int> a(n);
    for(int i = 0; i < n; i ++) {
        cin >> a[i];
    }
    sort(a.begin(), a.end());
    int ans = 1;
    for(int i = 1; i < n; i ++) {
        if(a[i] != a[i - 1]) {
            ans ++;
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
