#include <bits/stdc++.h>
using namespace std;
#define ll long long

const int MAX_N = 1e5;
vector<int> adj[MAX_N];
bool rel[MAX_N];
int ans[MAX_N];


void dfs(int u, int ind) {
	rel[u] = 1;
	ans[u] = max(ans[u], ind);
	for(int& v: adj[u]) {
		if(rel[v]) continue;
		dfs(v, ind);
	}
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

	int n, q; cin >> n >> q;
	for(int i = 0; i < n; i++) {
		rel[i] = 1;
		ans[i] = 0;
	}
	pair<int, int> queries[q];
	vector<pair<int, int>> edges;
	vector<bool> removed;
	for(int i = 0; i < q; i++) {
		char t; cin >> t;
		if(t == 'A') {
			int x, y; cin >> x >> y;
			queries[i] = {0, 69};
			edges.push_back({--x, --y});
			removed.push_back(0);
		} else if(t == 'R') {
			int e; cin >> e;
			queries[i] = {1, --e};
			removed[e] = 1;
		} else {
			int x; cin >> x;
			queries[i] = {2, --x};
			rel[x] = 0;
		}
	}
	for(int i = 0; i < edges.size(); i++) {
		if(!removed[i]) {
			pair<int, int> edge = edges[i];
			int u = edge.first, v = edge.second;
			adj[u].push_back(v);
			adj[v].push_back(u);
		}
	}
	for(int i = 0; i < n; i++) {
		if(rel[i]) {
			dfs(i, q);
		}
	}
	reverse(queries, queries + q);
	for(int i = 0; i < q; i++) {
		if(queries[i].first == 1) {
			pair<int, int> edge = edges[queries[i].second];
			int u = edge.first, v = edge.second;
			adj[u].push_back(v);
			adj[v].push_back(u);
			if(rel[u]) dfs(u, q-i-1);
			if(rel[v]) dfs(v, q-i-1);
		} else if(queries[i].first == 2) {
			int u = queries[i].second;
			if(!rel[u]) {
				dfs(u, q-i-1);
			}
		}
	}
	for(int i = 0; i < n; i++) {
		cout << ans[i] << '\n';
	}
    return 0;
}