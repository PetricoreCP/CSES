//https://cses.fi/problemset/task/1746
#include<bits/stdc++.h>
using namespace std;

constexpr int MOD = 1e9 + 7;

int32_t main() {
	ios::sync_with_stdio(false); 
	cin.tie(nullptr);	
	int tc = 1;
	//cin >> tc;
	while (tc --) {
		int n, m;
		cin >> n >> m;
		vector<int> a(n);
		for (int i = 0; i < n; i ++) {
			cin >> a[i];
		}
		vector<int> f(m + 1), r(m + 1);
		vector<int> dp(n);
		if (a[0] == 0) {
			dp[0] = m;
			for (int i = 1; i <= m; i ++) f[i] ++;
		}
		else {
			dp[0] = 1;
			f[a[0]] ++;
		}
		for (int i = 1; i < n; i ++) {
			if (a[i] != 0) {
				if (a[i] - 1 >= 1) dp[i] += f[a[i] - 1];
				dp[i] %= MOD;
				if (a[i] + 1 <= m) dp[i] += f[a[i] + 1];
				dp[i] %= MOD;
				dp[i] += f[a[i]];
				dp[i] %= MOD;
				for (int j = 1; j <= m; j ++) f[j] = 0;
				f[a[i]] = dp[i];
			}
			else {
				for (int j = 1; j <= m; j ++) r[j] = 0;
				for (int j = 1; j <= m; j ++) {
					if (j == 1) {
						r[j] += f[j];
						r[j] %= MOD;
						if (j != m) {
							r[j + 1] += f[j];
							r[j + 1] %= MOD;
						}
					}
					else if (j == m) {
						r[j - 1] += f[j];
						r[j] += f[j];
						r[j] %= MOD;
						r[j - 1] %= MOD;
					}
					else {
						r[j - 1] += f[j];
						r[j] += f[j];
						r[j + 1] += f[j];
						r[j - 1] %= MOD;
						r[j] %= MOD;
						r[j + 1] %= MOD;
					}
				}
				for (int j = 1; j <= m; j ++) {
					f[j] = r[j];
				}
				for (int j = 1; j <= m; j ++) {
					dp[i] += f[j];
					dp[i] %= MOD;
				}
			}
		}
		cout << dp[n - 1];
	}
	return 0;
}
