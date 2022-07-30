#include <bits/stdc++.h>
using namespace std;

vector<int> adj[200];
bool visited[200];
int cur_size;
void dfs(int node) {
	visited[node] = 1;
	cur_size++;
	for (int &n : adj[node]) {
		if(!visited[n]) {
			dfs(n);
		}
	}
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	freopen("moocast.in", "r", stdin);
	freopen("moocast.out", "w", stdout);
	int n; cin >> n;
	vector<pair<pair<int, int>, int>> wtalkies;
	for(int i = 0; i < n; i++) {
		int x, y, p;
		cin >> x >> y >> p;
		x--; y--;
		wtalkies.push_back({{x, y}, p});
	}
	for(int i = 0; i < n - 1; i++) {
		for(int j = i + 1; j < n; j++) {
			int x = wtalkies[i].first.first - wtalkies[j].first.first;
			int y = wtalkies[i].first.second - wtalkies[j].first.second;
			if(x*x + y*y <= wtalkies[i].second*wtalkies[i].second) {
				adj[i].push_back(j);
			}
			if(x*x + y*y <= wtalkies[j].second*wtalkies[j].second) {
				adj[j].push_back(i);
			}
		}
	}
	int ans = 0;
	for(int i = 0; i < n; i++) {
		if(!visited[i]) {
			memset(visited, 0, sizeof(visited));
			cur_size = 0;
			dfs(i);
			ans = max(ans, cur_size);
		}
	}
	cout << ans << '\n';
	return 0;
}