#include <bits/stdc++.h>
using namespace std;
const int MAX_N = 3000;

bool grid[MAX_N][MAX_N];
int adj[MAX_N][MAX_N];
int dx[4] = {0, 0, 1, -1};
int dy[4] = {1, -1, 0, 0};
int ans = 0;

void floodfill(int r, int c){
	if(grid[r][c])
        return;

	grid[r][c] = 1;
	ans++;
	if(adj[r][c] == 3) {
		for(int i = 0; i < 4; i++){
			int nr = r + dy[i];
			int nc = c + dx[i];
			floodfill(nr, nc);
		}
	}
	for(int i = 0; i < 4; i++) {
		int nr = r + dy[i];
		int nc = c + dx[i];
		adj[nr][nc]++;
		if(grid[nr][nc] && adj[nr][nc] == 3) {
			for(int j = 0; j < 4; j++) {
				int nnr = nr + dy[j];
				int nnc = nc + dx[j];
				floodfill(nnr, nnc);
			}
		}
	}
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	int n; cin >> n;
	for(int i = 0; i < n; i++) {
		int x, y; cin >> x >> y;
		x += 1000; y += 1000;
		ans--;
		floodfill(x, y);
		cout << ans << '\n';
	}
	return 0;
}