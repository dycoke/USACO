#include <bits/stdc++.h>
using namespace std;

vector<int> adj[100000];
int ans;

void dfs(int parent, int node) {
	int neighbors = 1;
	for(int& neighbor : adj[node]) {
		if(neighbor != parent) {
			neighbors++;
			dfs(node, neighbor);
		}
	}
	int a = (int) (ceil(log2(neighbors)));
	ans += a;
}
int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	int n; cin >> n;
	for(int i = 1; i < n; i++) {
		int a, b; cin >> a >> b;
		a--; b--;
		adj[a].push_back(b);
		adj[b].push_back(a);
	}
	ans = n - 1;
	dfs(-1, 0);
	cout << ans << '\n';
	return 0;
}