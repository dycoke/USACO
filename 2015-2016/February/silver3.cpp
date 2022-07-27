#include <bits/stdc++.h>
using namespace std;
const int MAX_N = 101;

int x_size, y_size, k, m;
bool visited[MAX_N][MAX_N][MAX_N];
int ans = 1e6;

void floodfill(int x, int y, int steps){
	if ((x < 0 || x > x_size || y < 0 || y > y_size) || visited[x][y][steps] || steps > k)
        return;
	
	ans = min(ans, abs(m - x - y));
	visited[x][y][steps] = 1;
	steps++;

	//empty either bucket
	floodfill(0, y, steps);
	floodfill(x, 0, steps);
	//fill either bucket
	floodfill(x_size, y, steps);
	floodfill(x, y_size, steps);
	//pour from one bucket to the other
	floodfill(min(x + y, x_size), max(0, x + y - min(x + y, x_size)), steps);
	floodfill(max(0, x + y - min(x + y, y_size)), min(x + y, y_size), steps);
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	freopen("pails.in", "r", stdin);
	freopen("pails.out", "w", stdout);
	cin >> x_size >> y_size >> k >> m;
	floodfill(0, 0, 0);
	cout << ans << '\n';
	return 0;
}