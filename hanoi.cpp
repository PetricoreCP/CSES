//https://cses.fi/problemset/task/2165
#include <bits/stdc++.h>
using namespace std;

vector<pair<int, int>> moves;

void hanoi(int n, int start, int end) {
	if(n == 1) {
		moves.push_back({start, end});
		return;
	}
	hanoi(n - 1, start, 6 - start - end);
	moves.push_back({start, end});
	hanoi(n - 1, 6 - start - end, end);
}

void solve() {
	int n;
	cin >> n;
	hanoi(n, 1, 3);
	cout << moves.size() << '\n';
	for(auto &m : moves) {
		cout << m.first << ' ' << m.second << '\n';
	}
}

int main() {
    ios::sync_with_stdio(false); cin.tie(nullptr);
    int tc = 1;
    //cin >> tc;
    while (tc--) solve();
    return 0;
}
