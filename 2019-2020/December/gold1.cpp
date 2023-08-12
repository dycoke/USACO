#include <bits/stdc++.h>
using namespace std;
#define ll long long

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
	freopen("pump.in", "r", stdin);
	freopen("pump.out", "w", stdout);
	int n, m; cin >> n >> m;
	array<int, 4> edges[m];
	for(array<int, 4>& edge: edges) {
		cin >> edge[0] >> edge[1] >> edge[2] >> edge[3];
		edge[0]--; edge[1]--;
	}
	sort(edges, edges+m, [](array<int, 4> a, array<int, 4> b) {return a[3] > b[3]; });
	vector<array<int, 2>> adj[n];
	int dist[n]; memset(dist, 0x3f, sizeof(dist));
	dist[0] = 0;
	bool visited[n];
	int ans = 0;
	for(array<int, 4>& edge: edges) {
		adj[edge[0]].push_back({edge[1], edge[2]});
		adj[edge[1]].push_back({edge[0], edge[2]});
		priority_queue<array<int, 2>> pq; pq.push({0, 0});
		memset(visited, 0, sizeof(visited));
		while(!pq.empty()) {
			int top = pq.top()[1]; pq.pop();
			if(visited[top]) continue;
			visited[top] = 1;
			for(array<int, 2> v: adj[top]) {
				if(dist[top] + v[1] <= dist[v[0]]) {
					dist[v[0]] = dist[top] + v[1];
					pq.push({-dist[v[0]], v[0]});
				}
			}
		}
		ans = max(ans, (1000000*edge[3])/dist[n-1]);
	}
	cout << ans << '\n';
	
    return 0;
}