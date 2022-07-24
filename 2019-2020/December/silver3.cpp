#include <bits/stdc++.h>
using namespace std;

vector<int> adj[100000];
bool farms[100000];
vector<int> components(100000);
int component;

void dfs(int parent, int node) {
	components[node] = component;
	for(int& child : adj[node]) {
		if(child != parent && farms[node] == farms[child]) {
			dfs(node, child);
		}
	}
	return;
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	freopen("milkvisits.in", "r", stdin);
	freopen("milkvisits.out", "w", stdout);
	int n, m; cin >> n >> m;
	string farm_types; cin >> farm_types;
	for(int i = 0; i < n; i++) {
		farms[i] = (farm_types[i] == 'H');
	}
	for(int i = 1; i < n; i++) {
		int a, b;
		cin >> a >> b;
		a--; b--;
		adj[a].push_back(b);
		adj[b].push_back(a);
	}
	for(int i = 0; i < m; i++) {
		if(!components[i]) {
			dfs(-1, i);
			component++;
		}
	}
	for(int i = 0; i < m; i++) {
		int a, b; char c;
		cin >> a >> b >> c;
		a--; b--;
		if(components[a] != components[b] || farms[a] == (c == 'H')) {
			cout << '1';
		} else {
			cout << '0';
		}
	}
	cout << '\n';
	return 0;
	
}
// 0 for G
// 1 for H
