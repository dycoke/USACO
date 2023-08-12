#include <bits/stdc++.h>
using namespace std;
#define ll long long

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	freopen("dining.in", "r", stdin);
	freopen("dining.out", "w", stdout);

	int n, m, k; cin >> n >> m >> k;
	vector<array<int, 2>> adj[n+1];
	for(int i = 0; i < m; i++) {
		int a, b, w; cin >> a >> b >> w;
		adj[--a].push_back({--b, w});
		adj[b].push_back({a, w});
	}
	priority_queue<pair<ll, int>> pq;
	pq.push({0, n-1});
	ll dist[n]; memset(dist, 0x3f, sizeof(dist));
	dist[n-1] = 0;
	bool visited[n+1]; memset(visited, 0, sizeof(visited));
	while(!pq.empty()) {
		int u = pq.top().second; pq.pop();
		if(visited[u]) continue;
		visited[u] = 1;
		for(array<int, 2> v: adj[u]) {
			if(dist[u] + v[1] < dist[v[0]]) {
				dist[v[0]] = dist[u] + v[1];
				pq.push({-dist[v[0]], v[0]});
			}
		}
	}

	for(int i = 0; i < k; i++) {
		int p, y; cin >> p >> y; --p;
		adj[n].push_back({p, (int) dist[p] - y});
	}
	pq.push({0, n});
	ll dist2[n+1]; memset(dist2, 0x3f, sizeof(dist2));
	dist2[n] = 0;
	memset(visited, 0, sizeof(visited));
	while(!pq.empty()) {
		int u = pq.top().second; pq.pop();
		if(visited[u]) continue;
		visited[u] = 1;
		for(array<int, 2> v: adj[u]) {
			if(dist2[u] + v[1] < dist2[v[0]]) {
				dist2[v[0]] = dist2[u] + v[1];
				pq.push({-dist2[v[0]], v[0]});
			}
		}
	}
	for(int i = 0; i < n-1; i++) {
		if(dist[i] >= dist2[i]) {
			cout << 1 << '\n';
		} else {
			cout << 0 << '\n';
		}
	}
	return 0;
}