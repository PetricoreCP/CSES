//https://cses.fi/problemset/task/1623
#include <bits/stdc++.h>
using namespace std;

void solve() {
	int n;
	cin >> n;
	vector<int> weights(n);
	for(int i = 0; i < n; i ++) {
		cin >> weights[i];
	}
	long long best = 1e9 * 20;
	for(int mask = 0; mask < (1 << n); mask ++) {
		long long a = 0, b = 0;
		for(int i = 0; i < n; i ++) {
			if((mask >> i) & 1) a += weights[i];
			else b += weights[i];
		}
		best = min(best, abs(a - b));
	}
	cout << best;
}

int main() {
    ios::sync_with_stdio(false); cin.tie(nullptr);
    int tc = 1;
    //cin >> tc;
    while (tc--) solve();
    return 0;
}
