//https://cses.fi/problemset/task/1624
#include <bits/stdc++.h>
using namespace std;
 
vector<string> board;
long long cnt = 0;
 
bool check(int row, int column) {
	for(int i = 0; i < 8; i ++) {
		if(board[i][column] == 'Q') return false;
	}
	for(int j = 0; j < 8; j ++) {
		if(board[row][j] == 'Q') return false;
	}
	int i = row, j = column;
	int m = min(i, j);
	i -= m; j -= m;
	while(i < 8 && j < 8) {
		if(board[i][j] == 'Q') return false;
		i ++;
		j ++;
	}
	i = row; j = column;
	m = min(7 - i, j);
	i += m;
	j -= m;
	while(i >= 0 && j < 8) {
		if(board[i][j] == 'Q') return false;
		i --;
		j ++;
	}
	return true;
}
 
void cntQueens(int row) {
	if(row == 8) {
		cnt ++;
		return;
	}
	for(int column = 0; column < 8; column ++) {
		if(board[row][column] == '.' && check(row, column)) {
			board[row][column] = 'Q';
			cntQueens(row + 1);
			board[row][column] = '.';
		}
	}
}
 
void solve() {
	for(int i = 0; i < 8; i ++) {
		string line;
		cin >> line;
		board.push_back(line);
	}
	cntQueens(0);
	cout << cnt;
}
 
int main() {
    ios::sync_with_stdio(false); cin.tie(nullptr);
    int tc = 1;
    //cin >> tc;
    while (tc--) solve();
    return 0;
}
