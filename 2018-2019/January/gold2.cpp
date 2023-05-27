#include <bits/stdc++.h>
using namespace std;

const int MAX_N = 1e5;
vector<int> adj[MAX_N];
int dist[MAX_N], subtree[MAX_N], leaves[MAX_N];
bool visited[MAX_N], visited1[MAX_N];
int ans = 0;

void dfs(int node) {
    visited[node] = 1;
    for(int& n: adj[node]) {
        if(!visited[n]) {
            dist[n] = dist[node]+1;
            dfs(n);
            subtree[node] = min(subtree[node], subtree[n]+1);
            leaves[node] += leaves[n];
        }
    }
}

void dfs2(int node) {
    visited1[node] = 1;
    if(subtree[node] <= dist[node]) {
        ans -= leaves[node]-1;
        return;
    }
    for(int& n: adj[node]) {
        if(!visited1[n]) {
            dfs2(n);
        }
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    freopen("atlarge.in", "r", stdin);
    freopen("atlarge.out", "w", stdout);
    int n, k; cin >> n >> k;
    for(int i = 1; i < n; i++) {
        int a, b; cin >> a >> b;
        adj[--a].push_back(--b);
        adj[b].push_back(a);
    }

    for(int i = 0; i < n; i++) {
        subtree[i] = INT_MAX;
        leaves[i] = 0;
        visited[i] = 0;
        visited1[i] = 0;
        if(adj[i].size() == 1) {
            subtree[i] = 0;
            leaves[i] = 1;
            ans++;
        }
    }
    dist[k] = 0; dfs(--k);
    dfs2(k);

    cout << ans << '\n';
    return 0;
}

/*
dist[i]: dist from k to node i
subtree[i]: min subtree size of tree at node i
leaves[i]: amount of leaves from subtree at node i

dfs at node k to find subtree and leaves
bfs at node k to find dist and ans

ans = num_leafs
if subtree[i] <= dist[i]:
    ans -= leaves[i]-1
    return
*/