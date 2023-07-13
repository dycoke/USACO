#include <bits/stdc++.h>
using namespace std;
#define ll long long

const int MAX_N = 1e5 + 5;
int n, m;
vector<int> observations[50005];
vector<int> adj[MAX_N];
bool visited[MAX_N];
vector<int> top_sort;

void dfs(int u) {
	visited[u] = 1;
	for(int v: adj[u]) {
		if(!visited[v]) dfs(v);
	}
	top_sort.push_back(u);
}

bool works(int x) {
	for(int i = 0; i < n; i++) {
		adj[i].clear();
		visited[i] = 0;
	}
	for(int i = 0; i < x; i++) {
		for(int j = 1; j < observations[i].size(); j++) {
			adj[observations[i][j-1]].push_back(observations[i][j]);
		}
	}
	top_sort.clear();
	for(int i = 0; i < n; i++) {
		if(!visited[i]) dfs(i);
	}
	reverse(top_sort.begin(), top_sort.end());
	int ind[n];
	for(int i = 0; i < n; i++) {
		ind[top_sort[i]] = i;
	}
	for(int i = 0; i < n; i++) {
		for(int v: adj[i]) {
			if(ind[v] <= ind[i]) {
				return 0;
			}
		}
	}
	return 1;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
	freopen("milkorder.in", "r", stdin);
	freopen("milkorder.out", "w", stdout);

	cin >> n >> m;
	for(int i = 0; i < n; i++) visited[i] = 0;
	for(int i = 0; i < m; i++) {
		int t; cin >> t;
		for(int j = 0; j < t; j++) {
			int c; cin >> c;
			observations[i].push_back(c-1);
		}
	}
	int l = 1, r = m;
	while(l < r) {
		int mid = l + (r-l+1)/2;
		if(works(mid)) {
			l = mid;
		} else {
			r = mid - 1;
		}
	}

	int indegree[n];
	for(int i = 0; i < n; i++) {
		adj[i].clear();
		visited[i] = 0;
		indegree[i] = 0;
	}

	for(int i = 0; i < l; i++) {
		for(int j = 1; j < observations[i].size(); j++) {
			adj[observations[i][j-1]].push_back(observations[i][j]);
			indegree[observations[i][j]]++;
		}
	}
	top_sort.clear();
	priority_queue<int, vector<int>, greater<int>> pq;
	for(int i = 0; i < n; i++) {
		if(indegree[i] == 0) pq.push(i);
	}
	while(!pq.empty()) {
		int u = pq.top(); pq.pop();
		top_sort.push_back(u);
		for(int v: adj[u]) {
			if(--indegree[v] == 0) {
				pq.push(v);
			}
		}
	}
	for(int i = 0; i < n; i++) {
		cout << top_sort[i] + 1;
		if(i < n-1) cout << ' ';
	}
	cout << '\n';
    return 0;
}
/*
5 4
2 1 5
2 1 2
2 2 4
2 5 3
*/