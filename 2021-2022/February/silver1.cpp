#include <bits/stdc++.h>
using namespace std;

vector<int> adj[500];
bool visited[500][500];

void dfs(int src, int node) {
	visited[src][node] = 1;
	for(int& n : adj[node]) {
		if(!visited[src][n]) {
			dfs(src, n);
		}
	}
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	int n; cin >> n;
	for(int i = 0; i < n; i++) {
		bool reached_i = 0;
		for(int j = 0; j < n; j++) {
			int p; cin >> p; p--;
			if(!reached_i) {
				adj[i].push_back(p);
				reached_i = (p == i);
			}
		}
	}
	for(int i = 0; i < n; i++) {
		dfs(i, i);
	}
	for(int i = 0; i < n; i++) {
		for(int& g : adj[i]) {
			if(visited[g][i]) {
				cout << g+1 << '\n';
				break;
			}
		}
	}
	return 0;
}