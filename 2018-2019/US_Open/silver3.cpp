#include <bits/stdc++.h>
using namespace std;
vector<vector<int>> adj;
vector<bool> visited;
vector<pair<int, int>> points;
int n, m;
int mnx, mny, mxx, mxy;
void dfs(int node) {
	mnx = min(mnx, points[node].first); mxx = max(mxx, points[node].first);
	mny = min(mny, points[node].second); mxy = max(mxy, points[node].second);
	visited[node] = 1;
	for(int neighbor : adj[node]) {
		if(!visited[neighbor]) {
			dfs(neighbor);
		}
	}
	return;
}
int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	freopen("fenceplan.in", "r", stdin);
	freopen("fenceplan.out", "w", stdout);
	cin >> n >> m;
	points = vector<pair<int, int>>(n);
	for(int i = 0; i < n; i++) {
		cin >> points[i].first >> points[i].second;
	}
	adj = vector<vector<int>>(n);
	visited = vector<bool>(n, 0);
	for(int i = 0; i < m; i++) {
		int a, b; cin >> a >> b;
		a--; b--;
		adj[a].push_back(b);
		adj[b].push_back(a);
	}
	int ans = 1e9;
	for(int i = 0; i < n; i++) {
		if(!visited[i]) {
			mnx = 1e8; mny = 1e8; mxx = -1; mxy = -1;
			dfs(i);
			ans = min(ans, 2*(mxx - mnx + mxy - mny));
		}
	}
	cout << ans << '\n';
	return 0;
}
