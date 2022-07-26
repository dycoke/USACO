#include <bits/stdc++.h>
using namespace std;

int n;
int curr_size = 0;
void gravity(vector<vector<int>>& grid) {
	for(vector<int>& col : grid) {
		vector<int> t(n);
		int j = n-1;
		for(int i = n-1; i >= 0; i--) {
			if(col[i]) {
				t[j] = col[i];
				j--;
			}
		}
		col = t;
	}
}

void floodfill(vector<vector<int>>& grid, vector<vector<bool>>& visited, int r, int c, int color){
	if ((r < 0 || r >= 10 || c < 0 || c >= n) || grid[r][c] != color || visited[r][c])
        return;

	visited[r][c] = 1;
	grid[r][c] = 0;
	curr_size++;
	floodfill(grid, visited, r, c + 1, color);
	floodfill(grid, visited, r, c - 1, color);
	floodfill(grid, visited, r - 1, c, color);
	floodfill(grid, visited, r + 1, c, color);
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	freopen("mooyomooyo.in", "r", stdin);
	freopen("mooyomooyo.out", "w", stdout);

	int k; cin >> n >> k;
	vector<vector<int>> grid(10, vector<int>(n));
	vector<vector<bool>> visited;
	for(int i = 0; i < n; i++) {
		string row; cin >> row;
		for (int j = 0; j < 10; j++) {
			grid[j][i] = row[j] - '0';
		}
	}

	bool keep_going = 1;
	while(keep_going) {
		keep_going = 0;
		visited = vector<vector<bool>>(10, vector<bool>(n));
		for(int i = 0; i < n; i++) {
			for(int j = 0; j < 10; j++) {
				if(!visited[j][i] && grid[j][i]) {
					vector<vector<int>> grid_copy(grid);
					curr_size = 0;
					floodfill(grid, visited, j, i, grid[j][i]);
					if(curr_size < k) {
						grid = vector<vector<int>>(grid_copy);
					} else {
						keep_going = 1;
					}
				}
			}
		}
		gravity(grid);
	}

	for(int i = 0; i < n; i++) {
		for(int j = 0; j < 10; j++) {
			cout << grid[j][i];
		}
		cout << '\n';
	}
	return 0;
}