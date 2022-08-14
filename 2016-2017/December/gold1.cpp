#include <bits/stdc++.h>
using namespace std;

vector<pair<int, int>> adj[1000];
bool visited[1000];
int curr_size;
void dfs(int node, int x) {
	curr_size++;
	visited[node] = 1;
	for (pair<int, int>& n : adj[node]) {
		if(!visited[n.first] && n.second <= x) {
			dfs(n.first, x);
		}
	}
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	freopen("moocast.in", "r", stdin);
	freopen("moocast.out", "w", stdout);
	int n; cin >> n;
	vector<pair<int, int>> cows(n);
	for (int i = 0; i < n; i++) {
		cin >> cows[i].first >> cows[i].second;
		cows[i].first--; cows[i].second--;
	}
	for(int i = 0; i < n - 1; i++) {
		for(int j = i + 1; j < n; j++) {
			int x = abs(cows[i].first - cows[j].first);
			int y = abs(cows[i].second - cows[j].second);
			adj[i].push_back({j, x*x + y*y});
			adj[j].push_back({i, x*x + y*y});
		}
	}
	int l = 0, r = 625000000;
	while(l < r) {
		int mid = l + (r - l) / 2;
		memset(visited, 0, sizeof(visited));
		curr_size = 0;
		dfs(0, mid);
		if(curr_size == n) {
			r = mid;
		} else {
			l = mid + 1;
		}
	}

	cout << l << '\n';
	return 0;
}