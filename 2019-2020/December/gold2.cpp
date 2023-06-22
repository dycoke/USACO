#include <bits/stdc++.h>
using namespace std;

const int MAX_N = 1e5;
const int LOG = 17;
vector<int> adj[MAX_N];
vector<array<int, 3>> queries[MAX_N];
int up[MAX_N][LOG], depth[MAX_N];
int type[MAX_N], recent[MAX_N];
bool ans[MAX_N];

int get_lca(int a, int b) {
    if(depth[a] < depth[b]) swap(a, b);
    int k = depth[a] - depth[b];
    for(int i = LOG-1; i >= 0; i--) {
        if(k & (1 << i)) {
            a = up[a][i];
        }
    }
    if(a == b) return a;

    for(int i = LOG-1; i >= 0; i--) {
        if(up[a][i] != up[b][i]) {
            a = up[a][i];
            b = up[b][i];
        }
    }

    return up[a][0];
}

void dfs1(int u, int p) {
    for(int& v: adj[u]) {
        if(v == p) continue;
        depth[v] = depth[u] + 1;
        up[v][0] = u;
        for(int i = 1; i < LOG; i++) {
            up[v][i] = up[up[v][i-1]][i-1];
        }
        dfs1(v, u);
    }
}

void dfs2(int u, int p) {
    //update the array
    int prevt = recent[type[u]];
    recent[type[u]] = u;
    for(auto& q: queries[u]) {
        if(recent[q[1]] == -1) continue;
        int lca_ab = get_lca(u, q[0]);
        int lca_ar = get_lca(u, recent[q[1]]);
        int lca_br = get_lca(q[0], recent[q[1]]);
        if(lca_br == lca_ab && lca_ar == recent[q[1]]) {
            ans[q[2]] = 1;
        }
    }
    for(int& v: adj[u]) {
        if(v == p) continue;
        dfs2(v, u);
    }
    recent[type[u]] = prevt;
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
    freopen("milkvisits.in", "r", stdin);
    freopen("milkvisits.out", "w", stdout);
    int n, m; cin >> n >> m;
    for(int i = 0; i < n; i++) {
        cin >> type[i];
        --type[i];
        ans[i] = 0;
        recent[i] = -1;
    }
    for(int i = 1; i < n; i++) {
        int a, b; cin >> a >> b;
        adj[--a].push_back(--b);
        adj[b].push_back(a);
    }
    dfs1(0, -1);
    for(int i = 0; i < m; i++) {
        int a, b, t; cin >> a >> b >> t;
        queries[--a].push_back({--b, --t, i});
        queries[b].push_back({a, t, i});
    }
    dfs2(0, -1);
    for(int i = 0; i < m; i++) {
        cout << ans[i];
    }
    cout << '\n';
    return 0;
}