#include <bits/stdc++.h>
using namespace std;
vector<pair<int, int>> adj[5000];
int k, num;

void dfs(int parent, int node) {
	for(pair<int, int>& child : adj[node]) {
		if(child.first != parent && child.second >= k) {
			num++;
			dfs(node, child.first);
		}
	}
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	freopen("mootube.in", "r", stdin);
	freopen("mootube.out", "w", stdout);
	int n, q; cin >> n >> q;
	for(int i = 1; i < n; i++) {
		int a, b, r;
		cin >> a >> b >> r;
		a--; b--;
		adj[a].push_back({b, r});
		adj[b].push_back({a, r});
	}
	for(int i = 0; i < q; i++) {
		int v; cin >> k >> v;
		num = 0;
		dfs(-1, v-1);
		cout << num << '\n';
	}
	return 0;
}
