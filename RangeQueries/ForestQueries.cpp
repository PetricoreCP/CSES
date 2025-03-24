// Range Queries
// Prefix Sum Matrix
// https://cses.fi/problemset/task/1652
#include <bits/stdc++.h>
using namespace std;

int main() 
{
    ios::sync_with_stdio(false); 
    cin.tie(nullptr);
    int n, q;
    cin >> n >> q;
    vector<string> grid(n);
    for (int i = 0; i < n; i ++) cin >> grid[i];
    vector<vector<int>> matrix(n + 1, vector<int>(n + 1));
    for (int i = 1; i <= n; i ++) for (int j = 1; j <= n; j ++) 
    {
        if (grid[i - 1][j - 1] == '*') matrix[i][j] ++;
        matrix[i][j] += matrix[i][j - 1];
    }
    for (int j = 1; j <= n; j ++) for (int i = 1; i <= n; i ++) matrix[i][j] += matrix[i - 1][j];
    while (q --) 
    {
        int y1, x1, y2, x2;
        cin >> y1 >> x1 >> y2 >> x2;
        cout << matrix[y2][x2] + matrix[y1 - 1][x1 - 1] - matrix[y2][x1 - 1] - matrix[y1 - 1][x2] << '\n';
    }
    return 0;
}
