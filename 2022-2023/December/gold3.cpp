#include <bits/stdc++.h>
using namespace std;

struct DSU {
	vector<int> e;
	DSU(int N) { e = vector<int>(N, -1); }
	
	int get(int x) { return e[x] < 0 ? x : e[x] = get(e[x]); }

	bool same_set(int a, int b) { return get(a) == get(b); }

	int size(int x) { return -e[get(x)]; }

	bool unite(int x, int y) {
		x = get(x), y = get(y);
		if (x == y) return false;
		if (e[x] > e[y]) swap(x, y);
		e[x] += e[y]; e[y] = x;
		return true;
	}
};

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int n, m; cin >> n >> m;
    vector<int> adj[n];
    int indegree[n]; memset(indegree, 0, sizeof(indegree));
    for(int i = 0; i < m; i++) {
        int a, b; cin >> a >> b;
        adj[--a].push_back(--b);
        adj[b].push_back(a);
        indegree[a]++; indegree[b]++;
    }

    bool visited[n];
    set<pair<int, int>> vert;
    for(int i = 0; i < n; i++) {
        visited[i] = 0;
        vert.insert({indegree[i], i});
    }

    int order[n], ind = n-1;
    while(!vert.empty()) {
        pair<int, int> u = *vert.begin();
        vert.erase(u);
        for(int& v: adj[u.second]) {
            if(vert.count({indegree[v], v})) {
                vert.erase({indegree[v], v});
                vert.insert({--indegree[v], v});
            }
        }
        order[ind] = u.second;
        ind--;
    }
    DSU dsu(n);
    long long ans = 0;
    for(int i = 0; i < n; i++) {
        visited[order[i]] = 1;
        int friends = 0;
        for(int& v: adj[order[i]]) {
            if(visited[v]) {
                dsu.unite(order[i], v);
                friends++;
            }
        }
        ans = max(ans, 1LL*friends*dsu.size(order[i]));
    }
    cout << ans << '\n';
    return 0;
}