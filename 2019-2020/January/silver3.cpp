#include <bits/stdc++.h>
using namespace std;

vector<pair<int, int>> adj[100000];
int component[100000], minw;

void dfs(int node, int cur_component) {
	component[node] = cur_component;
	for (auto &i : adj[node]) {
		if(!component[i.first] && i.second >= minw) {
			dfs(i.first, cur_component);
		}
	}
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	freopen("wormsort.in", "r", stdin);
	freopen("wormsort.out", "w", stdout);
	int n, m; cin >> n >> m;
	vector<int> order(n);
	bool already_sorted = 1;
	for(int i = 0; i < n; i++) {
		cin >> order[i];
		order[i]--;
		already_sorted = (already_sorted && order[i] == i);
	}
	if(already_sorted) {
		cout << -1 << '\n';
	} else {
		for(int i = 0; i < m; i++) {
			int a, b, w;
			cin >> a >> b >> w;
			a--; b--;
			adj[a].push_back({b, w});
			adj[b].push_back({a, w});
		}
		int left = 0, right = 1000000000, ans;
		while(left <= right) {
			minw = left + (right - left)/2;
			memset(component, 0, sizeof(component));
			int cur_component = 0;
			for(int i = 0; i < n; i++) {
				if(!component[i]) {
					dfs(i, ++cur_component);
				}
			}
			bool works = 0;
			for(int i = 0; i < n; i++) {
				if(component[i] == component[order[i]]) {
					works = 1;
				} else {
					works = 0;
					break;
				}
			}
			if(works) {
				ans = minw;
				left = minw + 1;
			} else {
				right = minw - 1;
			}
		}
		cout << ans << '\n';
	}
	return 0;
}