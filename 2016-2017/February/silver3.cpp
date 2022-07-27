#include <bits/stdc++.h>
using namespace std;

int n, num_cows;

void floodfill(vector<vector<int>>& grid, vector<vector<bool>>& visited, int r, int c){
	if ((r < 0 || r > 2*n || c < 0 || c > 2*n) || grid[r][c] == 1 || visited[r][c])
        return;
	else if(grid[r][c] == 2)
		num_cows++;
	visited[r][c] = 1;
	floodfill(grid, visited, r, c + 1);
	floodfill(grid, visited, r, c - 1);
	floodfill(grid, visited, r - 1, c);
	floodfill(grid, visited, r + 1, c);
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	freopen("countcross.in", "r", stdin);
	freopen("countcross.out", "w", stdout);
	int k, r;
	cin >> n >> k >> r;
	vector<vector<int>> grid(2*n + 1, vector<int>(2*n + 1));
	vector<vector<bool>> visited(2*n + 1, vector<bool>(2*n + 1));
	for(int i = 0; i < r; i++) {
		int r1, c1, r2, c2;
		cin >> r1 >> c1 >> r2 >> c2;
		r1*=2; c1*=2; r2*=2; c2*=2;
		r1--; c1--; r2--; c2--;
		int r = (r1 + r2)/2, c = (c1 + c2)/2;
		grid[r][c] = 1;
		grid[r][c + 1] = 1; grid[r][c - 1] = 1;
		grid[r + 1][c] = 1; grid[r - 1][c] = 1;
		grid[r1][c1] = 0; grid[r2][c2] = 0;
	}
	for(int i = 0; i < k; i++) {
		int r, c; cin >> r >> c;
		r*=2; c*=2; r--; c--;
		grid[r][c] = 2;
	}
	int ans = 0;
	for(int i = 0; i <= 2*n; i++) {
		for(int j = 0; j <= 2*n; j++) {
			if(grid[i][j] == 2 && !visited[i][j]) {
				num_cows = 0;
				floodfill(grid, visited, i, j);
				ans+=num_cows*(k - num_cows);
			}
		}
	}
	cout << ans/2 << '\n';
	return 0;
}
//0 is empty, 1 is wall, 2 is cow