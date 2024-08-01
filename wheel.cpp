//https://cses.fi/problemset/task/1090
#include <bits/stdc++.h>
using namespace std;
 
void solve() {
    int n, x;
    cin >> n >> x;
    vector<int> p(n);
    for(int i = 0; i < n; i ++) {
        cin >> p[i];
    }
    sort(p.rbegin(), p.rend());
    int ans = 0;
    int i = 0, j = n - 1;
    while(i <= j) {
        if(p[i] + p[j] <= x) {
            ans ++;
            i ++;
            j --;
        }
        else {
            ans ++;
            i ++;
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
