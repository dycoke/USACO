#include <bits/stdc++.h>
using namespace std;
vector<vector<int>> adj;
vector<bool> visited, color;
map<pair<int, int>, bool> edges;
int n, m;
bool bad = 0;

void dfs(int node, bool g) {
	visited[node] = 1;
	color[node] = g;
	for(int neighbor : adj[node]) {
		if(!visited[neighbor]) {
			if(edges[{node, neighbor}]) {
				dfs(neighbor, g);
			} else {
				dfs(neighbor, !g);
			}
		} else {
			if((color[node] == color[neighbor]) != edges[{node, neighbor}]) {
				bad = 1;
			}
		}
	}
	return;
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	freopen("revegetate.in", "r", stdin);
	freopen("revegetate.out", "w", stdout);
	cin >> n >> m;
	adj.resize(n);
	for(int i = 0; i < m; i++) {
		char same; int a, b; 
		cin >> same >> a >> b;
		a--; b--;
		edges[{a, b}] = (same == 'S');
		edges[{b, a}] = (same == 'S');
		adj[a].push_back(b);
		adj[b].push_back(a);
	}
	color.resize(n);
	visited = vector<bool>(n, 0);
	int components = 0;
	for(int i = 0; !bad && i < n; i++) {
		if(!visited[i]) {
			components++;
			dfs(i, 0);
		}
	}
	if(bad) {
		cout << 0 << '\n';
		cout << 1;
		for(int i = 0; i < components; i++) {
			cout << 0;
		}
		cout << '\n';
	}
	return 0;
}
