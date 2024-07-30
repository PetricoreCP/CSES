//https://cses.fi/problemset/task/1622
#include <bits/stdc++.h>
using namespace std;

void solve() {
	string s;
	cin >> s;
	sort(s.begin(), s.end());
	vector<string> ans;
	do {	
		ans.push_back(s);
	} while(next_permutation(s.begin(), s.end()));
	cout << ans.size() << '\n';
	for(auto &x : ans) cout << x << '\n';
}

int main() {
    ios::sync_with_stdio(false); cin.tie(nullptr);
    int tc = 1;
    //cin >> tc;
    while (tc--) solve();
    return 0;
}
