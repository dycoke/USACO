#include <bits/stdc++.h>
using namespace std;

int n, m, visits;
vector<bool> visited;
vector<vector<int>> adj;
void dfs(int node) {
    visited[node] = 1;
    visits++;
    for(auto& n : adj[node]) {
        if(!visited[n])
            dfs(n);
    }
    return;
}

int main() {
    ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
    freopen("closing.in", "r", stdin);
    freopen("closing.out", "w", stdout);
    cin >> n >> m;
    adj = vector<vector<int>>(n);
    visited = vector<bool>(n, 0);
    for(int i = 0; i < m; i++) {
        int a, b; cin >> a >> b;
        adj[--a].push_back(--b);
        adj[b].push_back(a);
    }
    int start = 0;
    vector<bool> closed(n);
    for(int i = 0; i < n; i++) {
        while(closed[start]) {
            start++;
        }
        visited = vector<bool>(closed);
        visits = 0;
        dfs(start);
        if(visits + i == n)
            cout << "YES" << endl;
        else
            cout << "NO" << endl;
        int c; cin >> c;
        closed[c - 1] = 1;
    }
    return 0;
}
