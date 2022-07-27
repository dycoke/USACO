#include <bits/stdc++.h>
using namespace std;
const int MAX_N = 4005;

int mnx, mny, mxx, mxy;
void floodfill(vector<vector<int>>& grid, vector<vector<bool>>& visited, int r, int c, int color){
	if ((r < mnx || r > mxx || c < mny || c > mxy) || grid[r][c] != color || visited[r][c])
		return;
	
	visited[r][c] = 1;
	floodfill(grid, visited, r, c + 1, color);
	floodfill(grid, visited, r, c - 1, color);
	floodfill(grid, visited, r - 1, c, color);
	floodfill(grid, visited, r + 1, c, color);
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	freopen("where.in", "r", stdin);
	freopen("where.out", "w", stdout);
	int n; cin >> n;
	vector<vector<int>> grid(n, vector<int>(n));
	vector<bool> color(26);
	int unique_colors = 0;
	for(int i = 0; i < n; i++) {
		string row; cin >> row;
		for(int j = 0; j < n; j++) {
			grid[i][j] = row[j] - 'A';
			if(!color[grid[i][j]]) {
				color[grid[i][j]] = 1;
				unique_colors++;
			}
		}
	}
	if(unique_colors < 2) {
		cout << "0\n";
		return 0;
	}
	vector<array<int, 4>> pcls;
	set<array<int, 4>> ans;
	for(int x1 = 0; x1 < n; x1++) {
		for(int y1 = 0; y1 < n; y1++) {
			for(int x2 = x1; x2 < n; x2++) {
				for(int y2 = y1; y2 < n; y2++) {
					vector<vector<bool>> visited(n, vector<bool>(n));
					vector<int> colors, components(26);
					mnx = x1, mny = y1, mxx = x2, mxy = y2;
					for(int i = x1; i <= x2; i++) {
						for(int j = y1; j <= y2; j++) {
							if(!visited[i][j]) {
								if(components[grid[i][j]] == 0) {
									colors.push_back(grid[i][j]);
								}
								components[grid[i][j]]++;
								floodfill(grid, visited, i, j, grid[i][j]);
							}
						}
					}
					if(colors.size() == 2 && ((components[colors[0]] == 1 && components[colors[1]] >= 2) || (components[colors[1]] == 1 && components[colors[0]] >= 2))) {
						pcls.push_back({mnx, mny, mxx, mxy});
						ans.insert({mnx, mny, mxx, mxy});
					}
				}
			}
		}
	}
	for(int i = 0; i < pcls.size() - 1; i++) {
		for(int j = i + 1; j < pcls.size(); j++) {
			if(pcls[i][0] >= pcls[j][0] && pcls[i][1] >= pcls[j][1] && pcls[i][2] <= pcls[j][2] && pcls[i][3] <= pcls[j][3]) {
				ans.erase(pcls[i]);
			} else if(pcls[i][0] <= pcls[j][0] && pcls[i][1] <= pcls[j][1] && pcls[i][2] >= pcls[j][2] && pcls[i][3] >= pcls[j][3]) {
				ans.erase(pcls[j]);
			}
		}
	}

	cout << ans.size() << '\n';
	return 0;
}