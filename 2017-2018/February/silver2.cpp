#include <bits/stdc++.h>
using namespace std;
const int MAX_N = 250;

pair<int, int> boots[MAX_N];
int tiles[MAX_N];
bool visited[MAX_N][MAX_N];
int n, b, ans = 1000;

void floodfill(int tile, int boot){
	if(tile >= n - 1) { //reached the end
		ans = min(ans, boot);
		return;
	}

	if(visited[tile][boot] || boots[boot].first < tiles[tile]) //visited before or too deep
		return;
	
	visited[tile][boot] = 1;
	for(int i = boot; i < b; i++) {
		for(int j = 0; j <= boots[i].second; j++) {
			if(boots[i].first >= tiles[tile]) {
				floodfill(tile + j, i);
			}
		}
	}
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	freopen("snowboots.in", "r", stdin);
	freopen("snowboots.out", "w", stdout);
	cin >> n >> b;
	for(int i = 0; i < n; i++) {
		cin >> tiles[i];
	}
	for(int i = 0; i < b; i++) {
		cin >> boots[i].first >> boots[i].second;
	}
	floodfill(0, 0);
	cout << ans << '\n';
	return 0;
}