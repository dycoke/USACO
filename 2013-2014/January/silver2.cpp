#include <bits/stdc++.h>
using namespace std;
const int MAX_N = 500;

int grid[MAX_N][MAX_N];
int row_num, col_num;
bool visited[MAX_N][MAX_N];
int cur_diff;

void floodfill(int r, int c, int prev) {
	if ((r < 0 || r >= row_num || c < 0 || c >= col_num) || abs(grid[r][c] - prev) > cur_diff || visited[r][c])
        return;
	
	visited[r][c] = 1;
	floodfill(r, c + 1, grid[r][c]);
	floodfill(r, c - 1, grid[r][c]);
	floodfill(r - 1, c, grid[r][c]);
	floodfill(r + 1, c, grid[r][c]);
}
int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	freopen("ccski.in", "r", stdin);
	freopen("ccski.out", "w", stdout);
	cin >> row_num >> col_num;
	int left = 0, right = 0;
	for(int i = 0; i < row_num; i++){
		for(int j = 0; j < col_num; j++){
			cin >> grid[i][j];
			right = max(right, grid[i][j]);
		}
	}
	vector<pair<int, int>> checkpoints;
	for(int i = 0; i < row_num; i++){
		for(int j = 0; j < col_num; j++){
			int x; cin >> x;
			if(x) {
				checkpoints.push_back({i, j});
			}
		}
	}
	int ans;
	while(left <= right) {
		cur_diff = left + (right - left)/2;
		memset(visited, 0, sizeof(visited));
		floodfill(checkpoints[0].first, checkpoints[0].second, grid[checkpoints[0].first][checkpoints[0].second]);
		bool works = 1;
		for(pair<int, int>& checkpoint : checkpoints) {
			if(!visited[checkpoint.first][checkpoint.second]) {
				works = 0;
				break;
			}
		}

		if(works) {
			right = cur_diff - 1;

		} else {
			left = cur_diff + 1;
		}
	}
	cout << left << '\n';
	return 0;
}