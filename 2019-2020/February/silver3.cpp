#include <bits/stdc++.h>
using namespace std;
vector<vector<int>> adj;
vector<int> times, copy_times;

void dfs(int parent, int node) {
	for(int child : adj[node]) {
		if(child != parent) {
			dfs(node, child);
			copy_times[node] += (12 - copy_times[child]);
		}
	}
	copy_times[node] %= 12;
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	freopen("clocktree.in", "r", stdin);
	freopen("clocktree.out", "w", stdout);
	int n; cin >> n;
	adj.resize(n);
	times.resize(n);
	for(int i = 0; i < n; i++)
		cin >> times[i];
	for(int i = 1; i < n; i++) {
		int a, b; 
		cin >> a >> b;
		a--; b--;
		adj[a].push_back(b);
		adj[b].push_back(a);
	}
	int ans = 0;
	for(int i = 0; i < n; i++) {
		copy_times = vector<int>(times);
		dfs(-1, i);
		if(copy_times[i] <= 1)
			ans++;
	}
	cout << ans << '\n';
}
