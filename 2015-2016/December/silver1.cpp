#include <bits/stdc++.h>
using namespace std;
const int MAX_N = 1000;

bool grid[MAX_N][MAX_N], visited[MAX_N][MAX_N];
int n, ans = 1;
map<pair<int, int>, vector<pair<int, int>>> switches;
bool next_to_visited(int r, int c) {
	vector<int> dx({-1, 0, 1, 0});
	vector<int> dy({0, 1, 0, -1});
	for (int i = 0; i < 4; i++) {
		int nr = r + dx[i];
		int nc = c + dy[i];
		if (nr >= 0 && nr < n && nc >= 0 && nc < n && visited[nr][nc])
			return 1;
	}
	return 0;
}

void floodfill(int r, int c){
	if ((r < 0 || r >= n || c < 0 || c >= n) || !grid[r][c] || visited[r][c])
        return;
	
	visited[r][c] = 1;
	for(pair<int, int>& room : switches[{r, c}]) {
		if(!grid[room.first][room.second]) {
			ans++;
			grid[room.first][room.second] = 1;
			if(next_to_visited(room.first, room.second))
				floodfill(room.first, room.second);
		}
	}
	floodfill(r, c + 1);
	floodfill(r, c - 1);
	floodfill(r - 1, c);
	floodfill(r + 1, c);
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	freopen("lightson.in", "r", stdin);
	freopen("lightson.out", "w", stdout);
	int m; cin >> n >> m;
	for(int i = 0; i < m; i++) {
		int a, b, x, y;
		cin >> a >> b >> x >> y;
		a--; b--; x--; y--;
		switches[{a, b}].push_back({x, y});
	}
	grid[0][0] = 1;
	floodfill(0, 0);
	cout << ans << '\n';
	return 0;
}