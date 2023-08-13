#include <bits/stdc++.h>
using namespace std;
#define ll long long

const int MAX_N = 1e5;
vector<int> adj[MAX_N];
int leaves[MAX_N], depth[MAX_N];
int length[MAX_N]; ll path[MAX_N];
ll total = 0, ans = LLONG_MAX;


void dfs1(int u) {
	leaves[u] = 0;
	if(adj[u].size() == 0) {
		total += path[u];
		leaves[u] = 1;
	}
	depth[u] = 0;
	for(int v: adj[u]) {
		path[v] = path[u] + length[v] + 1;
		depth[v] = depth[u] + 1;
		dfs1(v);
		leaves[u] += leaves[v];
	}
}

void dfs2(int u) {
	ll prev = total;
	if(u != 0) total = (total - 1LL*leaves[u]*(length[u]+1) + 3*(leaves[0]-leaves[u]));
	ans = min(ans, total);
	for(int v: adj[u]) {
		if(adj[v].size() != 0) {
			dfs2(v);
		}
	}
	total = prev;
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	freopen("dirtraverse.in", "r", stdin);
	freopen("dirtraverse.out", "w", stdout);

	int n; cin >> n;
	for(int i = 0; i < n; i++) {
		string s; cin >> s;
		length[i] = s.size();
		int m; cin >> m;
		for(int j = 0; j < m; j++) {
			int a; cin >> a;
			adj[i].push_back(--a);
		}
	}
	path[0] = 0;
	dfs1(0);
	total -= leaves[0];
	dfs2(0);
	cout << ans << '\n';
	return 0;
}