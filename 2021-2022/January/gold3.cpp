#include <bits/stdc++.h>
using namespace std;
#define ll long long

const int MAX_N = 1e5 + 5;
vector<int> adj[MAX_N];
int ans[MAX_N], order[MAX_N], cur, depth = 0;

void dfs(int u) {
    depth = max(depth, ans[u]);
    order[u] = cur--;
    for(int i = adj[u].size() - 1; i >= 0; i--) {
        ans[adj[u][i]] = ans[u] + 1;
        dfs(adj[u][i]);
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    // freopen("io.in", "r", stdin);
    // freopen("io.out", "w", stdout);

    int n; cin >> n;
    for(int i = 1; i <= n; i++) {
        int a; cin >> a;
        adj[a+1].push_back(i);
    }
    cur = n+1;
    dfs(n+1);

    int k = n+1;
    cout << k << '\n';
    for(int i = 1; i <= n; i++) {
        // cout << ans[i] << ' ';
        cout << (ll) (depth - ans[i])*k + order[i] << '\n';
    }
    return 0;
}
/*
counter example
2
0 2 3 4
4
2 4 4 4
need more than just k = 1

6
2 2 4 5 6 6

tree
3 -> 1
3 -> 2
5 -> 3
6 -> 4

*/