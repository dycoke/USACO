#include <bits/stdc++.h>
using namespace std;
#define ll long long

vector<int> adj[100000], components[100000];
int component[100000], cur_component;

void dfs(int node) {
	component[node] = cur_component;
	for (int &n : adj[node]) {
		if(component[n] == -1) {
			dfs(n);
		}
	}
}

ll cost(int a, int b) {
	int dist = 100000;
	for(int& c : components[a]) {
		int t = lower_bound(components[b].begin(), components[b].end(), c) - components[b].begin();
		if(t > 0) {
			dist = min(dist, abs(components[b][t-1] - c));
		}
		if(t < components[b].size()) {
			dist = min(dist, abs(components[b][t] - c));
		}
	}
	return (ll) dist * dist;
}

void solve_tc() {
	int n, m; cin >> n >> m;
	for(int i = 0; i < n; i++) {
		adj[i].clear();
		components[i].clear();
		component[i] = -1;
	}
	for(int i = 0; i < m; i++) {
		int a, b; cin >> a >> b;
		a--; b--;
		adj[a].push_back(b);
		adj[b].push_back(a);
	}
	cur_component = 0;
	for(int i = 0; i < n; i++) {
		if(component[i] == -1) {
			dfs(i);
			cur_component++;
		}
	}
	for(int i = 0; i < n; i++) {
		components[component[i]].push_back(i);
	}

	ll ans = cost(component[0], component[n-1]);
	for(int i = 1; i < cur_component - 1; i++) {
		ans = min(ans, cost(i, component[0]) + cost(i, component[n-1]));
	}
	cout << ans << '\n';
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	int t; cin >> t;
	while(t--) {
		solve_tc();
	}
	return 0;
}