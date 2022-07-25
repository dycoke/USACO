#include <bits/stdc++.h>
using namespace std;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	freopen("planting.in", "r", stdin);
	freopen("planting.out", "w", stdout);
	int n; cin >> n;
	vector<int> adj(n);
	int ans = 0;
	for(int i = 1; i < n; i++) {
		int a, b; cin >> a >> b;
		a--; b--;
		adj[a]++; adj[b]++;
		ans = max({ans, adj[a], adj[b]});
	}
	cout << ans + 1 << '\n';
	return 0;
}